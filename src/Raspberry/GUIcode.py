# Form implementation generated from reading ui file 'GUIsplashy.ui'


import sys
from PySide6 import QtCore, QtGui, QtWidgets
from PySide6.QtWidgets import QTableWidgetItem

#python file GUIsplashy.py generated from GUIsplashy.ui 
#USING COMMAND:  
#   cd /home/gianluca/Desktop/splashy/python_env
#   pyuic5 GUIsplashy.ui  -o GUIsplashy.py
##########################################################################################################
class Ui_MainWindowSplashy(object):
    def setupUi(self, MainWindowSplashy):
        MainWindowSplashy.setObjectName("MainWindowSplashy")
        MainWindowSplashy.resize(800, 406)
        MainWindowSplashy.setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.637368, y2:0.943, stop:0 rgba(127, 163, 216, 255), stop:0.989637 rgba(236, 245, 255, 255))")
        self.centralwidget = QtWidgets.QWidget(MainWindowSplashy)
        self.centralwidget.setObjectName("centralwidget")
        self.tableRanking = QtWidgets.QTableWidget(self.centralwidget)
        self.tableRanking.setGeometry(QtCore.QRect(20, 50, 351, 121))
        self.tableRanking.setObjectName("tableRanking")
        self.tableRanking.setColumnCount(3)
        self.tableRanking.setRowCount(3)
        item = QtWidgets.QTableWidgetItem()
        self.tableRanking.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableRanking.setVerticalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableRanking.setVerticalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableRanking.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableRanking.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableRanking.setHorizontalHeaderItem(2, item)
        self.tableCurrentUser = QtWidgets.QTableWidget(self.centralwidget)
        self.tableCurrentUser.setGeometry(QtCore.QRect(120, 240, 501, 51))
        self.tableCurrentUser.setObjectName("tableCurrentUser")
        self.tableCurrentUser.setColumnCount(4)
        self.tableCurrentUser.setRowCount(1)
        item = QtWidgets.QTableWidgetItem()
        self.tableCurrentUser.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableCurrentUser.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableCurrentUser.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableCurrentUser.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableCurrentUser.setHorizontalHeaderItem(3, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableCurrentUser.setItem(0, 0, item)
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(20, 20, 211, 17))
        self.label.setStyleSheet("background: transparent")
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(490, 30, 111, 17))
        self.label_2.setStyleSheet("background: transparent")
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(190, 210, 161, 17))
        self.label_3.setAutoFillBackground(False)
        self.label_3.setStyleSheet("background: transparent")
        self.label_3.setObjectName("label_3")
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(480, 110, 260, 27))
        self.layoutWidget.setObjectName("layoutWidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.label_4 = QtWidgets.QLabel(self.layoutWidget)
        self.label_4.setStyleSheet("")
        self.label_4.setObjectName("label_4")
        self.horizontalLayout.addWidget(self.label_4)
        self.progressBar = QtWidgets.QProgressBar(self.layoutWidget)
        self.progressBar.setStyleSheet("background: white")
        self.progressBar.setProperty("value", 24)
        self.progressBar.setObjectName("progressBar")
        self.horizontalLayout.addWidget(self.progressBar)
        self.labelSplashyWeeklyGoal = QtWidgets.QLabel(self.layoutWidget)
        self.labelSplashyWeeklyGoal.setStyleSheet("background: transparent")
        self.labelSplashyWeeklyGoal.setObjectName("labelSplashyWeeklyGoal")
        self.horizontalLayout.addWidget(self.labelSplashyWeeklyGoal)
        self.layoutWidget1 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget1.setGeometry(QtCore.QRect(480, 70, 172, 19))
        self.layoutWidget1.setObjectName("layoutWidget1")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.layoutWidget1)
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_6 = QtWidgets.QLabel(self.layoutWidget1)
        self.label_6.setObjectName("label_6")
        self.horizontalLayout_2.addWidget(self.label_6)
        self.labelPlasticSaved = QtWidgets.QLabel(self.layoutWidget1)
        self.labelPlasticSaved.setStyleSheet("background: transparent")
        self.labelPlasticSaved.setObjectName("labelPlasticSaved")
        self.horizontalLayout_2.addWidget(self.labelPlasticSaved)
        MainWindowSplashy.setCentralWidget(self.centralwidget)

        self.retranslateUi(MainWindowSplashy)
        QtCore.QMetaObject.connectSlotsByName(MainWindowSplashy)

    def retranslateUi(self, MainWindowSplashy):
        _translate = QtCore.QCoreApplication.translate
        MainWindowSplashy.setWindowTitle(_translate("MainWindowSplashy", "MainWindow"))
        item = self.tableRanking.verticalHeaderItem(0)
        item.setText(_translate("MainWindowSplashy", "1place"))
        item = self.tableRanking.verticalHeaderItem(1)
        item.setText(_translate("MainWindowSplashy", "2place"))
        item = self.tableRanking.verticalHeaderItem(2)
        item.setText(_translate("MainWindowSplashy", "3place"))
        item = self.tableRanking.horizontalHeaderItem(0)
        item.setText(_translate("MainWindowSplashy", "RankingPosition"))
        item = self.tableRanking.horizontalHeaderItem(1)
        item.setText(_translate("MainWindowSplashy", "Nickname"))
        item = self.tableRanking.horizontalHeaderItem(2)
        item.setText(_translate("MainWindowSplashy", "TotalLiters"))
        item = self.tableCurrentUser.verticalHeaderItem(0)
        item.setText(_translate("MainWindowSplashy", "CurrentUser"))
        item = self.tableCurrentUser.horizontalHeaderItem(0)
        item.setText(_translate("MainWindowSplashy", "Nickname"))
        item = self.tableCurrentUser.horizontalHeaderItem(1)
        item.setText(_translate("MainWindowSplashy", "DailyLiters"))
        item = self.tableCurrentUser.horizontalHeaderItem(2)
        item.setText(_translate("MainWindowSplashy", "TotalLiters"))
        item = self.tableCurrentUser.horizontalHeaderItem(3)
        item.setText(_translate("MainWindowSplashy", "CurrentPosition"))
        __sortingEnabled = self.tableCurrentUser.isSortingEnabled()
        self.tableCurrentUser.setSortingEnabled(False)
        self.tableCurrentUser.setSortingEnabled(__sortingEnabled)
        self.label.setText(_translate("MainWindowSplashy", "RANKING OF THE WEEK"))
        self.label_2.setText(_translate("MainWindowSplashy", "SPLASHY STATS"))
        self.label_3.setText(_translate("MainWindowSplashy", "CURRENT USER STATS"))
        self.label_4.setText(_translate("MainWindowSplashy", "WEEKLY GOAL"))
        self.labelSplashyWeeklyGoal.setText(_translate("MainWindowSplashy", "TextLabel"))
        self.label_6.setText(_translate("MainWindowSplashy", "PLASTIC SAVED:"))
        self.labelPlasticSaved.setText(_translate("MainWindowSplashy", "TextLabel"))


    #ADDING FUNCTIONALITIES TO THE GUI
    #########################################################################################################################à
    # define constant variables value

        splashyWeeklyGoal = 1400 #in liters
        waterPlasticRatio = 0.2 #kilograms of plastic per liter of water

    # read value from fluxometer and RFID sensor
        litersErogated = 1 #readFluxometer()
        userID = 1 #readRFID()

    # update user stats in database
        #userDailyLiters = userDailyLiters + litersErogated
        #userTotalLiters = userTotalLiters + litersErogated

    #QUERY NEEDED
        #firstPlace (nickname, totalLiters)
        #secondPlace (nickname, totalLiters)
        #thirdPlace (nickname, totalLiters)

        #current user (nickname, dailyLiters, totalLiters, rankingPosition)  <-given NFC-ID
        getFromDB = 1

    
    # read values from DataBase ####################################
        litersOfTheWeek = getFromDB 
        plasticSaved = 0
        plasticSaved = plasticSaved + litersErogated * waterPlasticRatio

        userNickname = getFromDB
        userDailyLiters = getFromDB
        userTotalLiters = getFromDB
        userRankingPosition = getFromDB

        firstNickname = getFromDB
        secondNickname = getFromDB
        thirdNickname = getFromDB

        firstTotalLiters = getFromDB
        secondTotalLiters = getFromDB
        thirdTotalLiters = getFromDB


        
    # update text of the labels, tables, ecc with the variables value
        
        #progress bar
        self.progressBar.setMaximum(splashyWeeklyGoal)  # Imposta il valore massimo a 40
        self.progressBar.setValue(litersOfTheWeek)    # Imposta il valore corrente (default è 0)

        #labels
        self.labelSplashyWeeklyGoal.setText(str(splashyWeeklyGoal) + "L")
        self.labelPlasticSaved.setText(str(plasticSaved) + "Kg")

        #table user
        self.tableCurrentUser.setItem(0,0,QTableWidgetItem(str(userNickname)))
        self.tableCurrentUser.setItem(0,1,QTableWidgetItem(str(userDailyLiters)))
        self.tableCurrentUser.setItem(0,2,QTableWidgetItem(str(userTotalLiters)))
        self.tableCurrentUser.setItem(0,3,QTableWidgetItem(str(userRankingPosition)))

        #table ranking column position
        self.tableRanking.setItem(0,0,QTableWidgetItem("1st"))
        self.tableRanking.setItem(1,0,QTableWidgetItem("2nd"))   
        self.tableRanking.setItem(2,0,QTableWidgetItem("3rd"))
        #table ranking column nickname
        self.tableRanking.setItem(0,1,QTableWidgetItem(str(firstNickname)))
        self.tableRanking.setItem(1,1,QTableWidgetItem(str(secondNickname)))   
        self.tableRanking.setItem(2,1,QTableWidgetItem(str(thirdNickname)))
        #table ranking column totalLiters
        self.tableRanking.setItem(0,2,QTableWidgetItem(str(firstTotalLiters)))
        self.tableRanking.setItem(1,2,QTableWidgetItem(str(secondTotalLiters)))   
        self.tableRanking.setItem(2,2,QTableWidgetItem(str(thirdTotalLiters))) 


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindowSplashy = QtWidgets.QMainWindow()
    ui = Ui_MainWindowSplashy()
    ui.setupUi(MainWindowSplashy)
    MainWindowSplashy.show()
    sys.exit(app.exec())
