
import numpy as np
import matplotlib.pyplot as plt
from sklearn import metrics
from sklearn.metrics import confusion_matrix
from sklearn.metrics import multilabel_confusion_matrix





data = np.loadtxt('matrixdata.txt')
arvaus = np.loadtxt('kp.txt')
ar = np.array(data)
kp = np.array(arvaus)
print(len(kp),len(ar))

#actual = ar
#predicted = ar

cm = multilabel_confusion_matrix(ar, kp , labels =["up", "down", "left", "right"])

cm_display = metrics.ConfusionMatrixDisplay(confusion_matrix = confusion_matrix, display_labels = [True,False])

cm_display.plot()
plt.show() 