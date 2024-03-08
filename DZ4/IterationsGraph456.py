import matplotlib.pyplot as pyplot
import numpy as np

ys1 = np.loadtxt('build/res4.txt')
ys2 = np.loadtxt('build/res5.txt')
ys3 = np.loadtxt('build/res6.txt')
xs = np.arange(500, 1000, 10)

#параметры фигуры
fig, ax = pyplot.subplots(figsize=(16, 9), dpi=500)

#Включаем видимость сетки и делений и вводим их параметры ниже (Если включить сетку ниже парамтеров, то параметры не присвоятся)
ax.minorticks_on()

# #  Устанавливаем интервал основных делений X_2:
# ax.xaxis.set_major_locator(ticker.MultipleLocator(0.05))
# #  Устанавливаем интервал вспомогательных делений X_2:
# ax.xaxis.set_minor_locator(ticker.MultipleLocator(0.01))
#
# #  Тоже самое проделываем с делениями на оси Y_1:
# ax.yaxis.set_major_locator(ticker.MultipleLocator(0.25))
# ax.yaxis.set_minor_locator(ticker.MultipleLocator(0.05))
# ax.xaxis.set_minor_locator(ticker.MultipleLocator(0.0001))

#название графика с условием для переноса строки и центрированием(pad - отступ
ax.set_title('Сравнение скорости сходимости по Итерациям SIMs')

#сетка основная и второстепенная
ax.grid(which='major', color = 'gray')
ax.grid(which='minor', color = 'gray', linestyle = '--')

#Добавление самого графика и (в конце присваивает наличие леге label =...) и настройка цветов https://pyprog.pro/mpl/mpl_plot.html
ax.plot(xs, ys1, c='orange', zorder=10, linewidth=2, label='Метод Якоби')
ax.plot(xs, ys2, c='blue', zorder=10, linewidth=2, label='Метод Гаусса-Зейделя')
ax.plot(xs, ys3, c='green', zorder=10, linewidth=2, label='Матрица простой итерации')


ax.set_xlabel('Длина стороны матрицы', fontsize=14)
ax.set_ylabel('Число итераций', fontsize=14)

#Добавление легенды: https://pyprog.pro/mpl/mpl_adding_a_legend.html
ax.legend(shadow = False, loc = 'upper left', fontsize = 16)

pyplot.savefig("Iterations_Graph.jpg", bbox_inches='tight')

