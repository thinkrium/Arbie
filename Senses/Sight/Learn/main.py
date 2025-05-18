import cv2
import mediapipe as mp

import csv
import os
import numpy as np

import pandas as pd
from sklearn.model_selection import train_test_split

from sklearn.pipeline import make_pipeline
from sklearn.preprocessing import StandardScaler

from sklearn.linear_model import LogisticRegression, RidgeClassifier
from sklearn.ensemble import RandomForestClassifier, GradientBoostingClassifier

from sklearn.metrics import accuracy_score # Accuracy metrics
import pickle

import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

try:
    #s.bind(socket.gethostname(),  51234 )
    s.connect((socket.gethostname(),  54000 ))
    #clientSocket, address = s.accept()
except:
    pass
mp_drawing = mp.solutions.drawing_utils
mp_holistic = mp.solutions.holistic

# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    cap = cv2.VideoCapture("http://192.168.1.2:4747/video")

    # Initiate holistic model
    with mp_holistic.Holistic(min_detection_confidence=0.5, min_tracking_confidence=0.5) as holistic:

        class_name = "Happy"
        # tea/ching = True
        training = False
        teaching = False
        # training = True
        # new_model = False
        # drawOnImage = True
        drawOnImage = False

        messageToSend = ''

        global row
        while cap.isOpened():
            ret, frame = cap.read()

            # Recolor Feed
            image = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            image = cv2.flip(image, 1)
            image.flags.writeable = False

            # Make Detections
            results = holistic.process(image)

            image.flags.writeable = True

            # Recolor image back to BGR for rendering
            image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
             #drawing utilities

            if (drawOnImage):
                #
                # 1. Draw face landmarks
                mp_drawing.draw_landmarks(image, results.face_landmarks, mp_holistic.FACEMESH_CONTOURS,
                                          mp_drawing.DrawingSpec(color=(80, 110, 10), thickness=1, circle_radius=1),
                                          mp_drawing.DrawingSpec(color=(80, 256, 121), thickness=1, circle_radius=1)
                                          )

                # 2. Right hand
                mp_drawing.draw_landmarks(image, results.right_hand_landmarks, mp_holistic.HAND_CONNECTIONS,
                                          mp_drawing.DrawingSpec(color=(80, 22, 10), thickness=2, circle_radius=4),
                                          mp_drawing.DrawingSpec(color=(80, 44, 121), thickness=2, circle_radius=2)
                                          )

                # 3. Left Hand
                mp_drawing.draw_landmarks(image, results.left_hand_landmarks, mp_holistic.HAND_CONNECTIONS,
                                          mp_drawing.DrawingSpec(color=(121, 22, 76), thickness=2, circle_radius=4),
                                          mp_drawing.DrawingSpec(color=(121, 44, 250), thickness=2, circle_radius=2)
                                          )

                # 4. Pose Detections
                mp_drawing.draw_landmarks(image, results.pose_landmarks, mp_holistic.POSE_CONNECTIONS,
                                          mp_drawing.DrawingSpec(color=(245, 117, 66), thickness=2, circle_radius=4),
                                          mp_drawing.DrawingSpec(color=(245, 66, 230), thickness=2, circle_radius=2)
                                          )

            #drawing utilities

            try:

                if (teaching):

                # ###################################################################################
                    if ( os.path.isfile("coords.csv") == False):
                        num_coords = len(results.pose_landmarks.landmark) + len(results.face_landmarks.landmark)

                        landmarks = ['class']
                        for val in range(1, num_coords + 1):
                            landmarks += ['x{}'.format(val), 'y{}'.format(val), 'z{}'.format(val), 'v{}'.format(val)]

                        with open('coords.csv', mode='w', newline='') as f:
                            csv_writer = csv.writer(f, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
                            csv_writer.writerow(landmarks)


                    # Extract Pose landmarks
                    pose = results.pose_landmarks.landmark
                    pose_row = list(np.array(
                        [[landmark.x, landmark.y, landmark.z, landmark.visibility] for landmark in pose]).flatten())

                    # Extract Face landmarks
                    face = results.face_landmarks.landmark
                    face_row = list(np.array(
                        [[landmark.x, landmark.y, landmark.z, landmark.visibility] for landmark in face]).flatten())

                    # Concate rows
                    row = pose_row + face_row

                    # Append class name
                    row.insert(0, class_name)

                    # Export to CSV
                    with open('coords.csv', mode='a', newline='') as f:
                        csv_writer = csv.writer(f, delimiter=',', quotechar='"', quoting=csv.QUOTE_MINIMAL)
                        csv_writer.writerow(row)
    #########################################################################################
                if (training) :
            ######################################################################################
                    df = pd.read_csv('coords.csv')

                    X = df.drop('class', axis=1)  # features
                    y = df['class']  # target value
                    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=1234)

                    pipelines = {
                        # 'lr': make_pipeline(StandardScaler(), LogisticRegression()),
                        # 'rc': make_pipeline(StandardScaler(), RidgeClassifier()),
                        'rf': make_pipeline(StandardScaler(), RandomForestClassifier()),
                        # 'gb': make_pipeline(StandardScaler(), GradientBoostingClassifier()),
                    }

                    # pipeline  = make_pipeline(StandardScaler(), RandomForestClassifier()),

                    fit_models = {}

                    for algo, pipeline in pipelines.items():
                        model = pipeline.fit(X_train, y_train)
                        fit_models[algo] = model

                    if (os.path.isfile("body_language.pkl") == False):

                        with open('body_language.pkl', 'wb') as f:
                            pickle.dump(fit_models['rf'], f)

                if(teaching == False and training == False):
                    # Extract Pose landmarks
                    pose = results.pose_landmarks.landmark
                    pose_row = list(np.array(
                        [[landmark.x, landmark.y, landmark.z, landmark.visibility] for landmark in pose]).flatten())

                    # Extract Face landmarks
                    face = results.face_landmarks.landmark
                    face_row = list(np.array(
                        [[landmark.x, landmark.y, landmark.z, landmark.visibility] for landmark in face]).flatten())

                    # Concate rows
                    row = pose_row + face_row

                    with open('body_language.pkl', 'rb') as f:
                        model = pickle.load(f)

                        X = pd.DataFrame([row])
                        body_language_class = model.predict(X)[0]
                        body_language_prob = model.predict_proba(X)[0]


                        if(  round(body_language_prob[np.argmax(body_language_prob)], 2) > .75):
                            cv2.rectangle(image, (0, 0), (250, 60), (245, 117, 16), -1)

                            # Display Class
                            cv2.putText(image, 'CLASS'
                                        , (95, 12), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 1, cv2.LINE_AA)
                            cv2.putText(image, body_language_class.split(' ')[0]
                                        , (90, 40), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2, cv2.LINE_AA)

                            # Display Probability
                            cv2.putText(image, 'PROB'
                                        , (15, 12), cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 0, 0), 1, cv2.LINE_AA)
                            cv2.putText(image, str(round(body_language_prob[np.argmax(body_language_prob)], 2))
                                        , (10, 40), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2, cv2.LINE_AA)

                            if(messageToSend != body_language_class.split(' ')[0]):
                                messageToSend = body_language_class.split(' ')[0]
                                s.sendall(str(messageToSend).encode())
  ###############################################################################################
            except Exception  as e:
                print(e)

                pass

            cv2.imshow('Raw Webcam Feed', image)

            if cv2.waitKey(10) & 0xFF == ord('q'):
                break

    cap.release()
    cv2.destroyAllWindows()