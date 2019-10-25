#### 1.delegate



#### 2.qapplication
```Python
import sys
from PySide import QtCore,QtGui

class MainUI(QtGui.QWidget):

    def __init__(self,parent=None):
        super(MainUI, self).__init__(parent)

if __name__ == "__main__":
    app = QtGui.QApplication(sys.argv)
    mainUI = MainUI()
    mainUI.show()
    sys.exit(app.exec_())
```