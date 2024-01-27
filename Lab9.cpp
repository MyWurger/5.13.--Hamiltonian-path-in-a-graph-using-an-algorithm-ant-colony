/********************************************************************************
 * Л А Б О Р А Т О Р Н А Я   Р А Б О Т А  №9  З А   5   С Е М Е С Т Р   С  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab9                                               *
 * File Name     : Lab9. CPP                                                    *
 * Programmer(s) : Викулов Д.Г.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 10/10/23                                                     *
 * Last Revision : 22/10/23                                                     *
 * Comment(s)    : Программа, находящая гамильтонов путь в графе при помощи     *
 *                 алгоритма муравьиной колонии. Результатом работы является    *
 *                 маршрут, заданный списком рёбер                              *
 ********************************************************************************/


#include <iostream>              // стандартные потоки ввода/вывода
#include <vector>                // работа с векторами для удобства быстрого извлечения и удаления элементов
#include <fstream>               // работа с потоками ввода/вывода для файла
#include <iomanip>               // библиотека с модификатором setw
#include <graphviz/gvc.h>        // библиотека Graphviz для графического изображения графа по матрице смежности
#include <opencv2/opencv.hpp>    // заголовок, подтягивающий все функции OpenCv

using namespace std;             // используем пространство имён std


/*******************************************************************/
/*            Г Л О Б А Л Ь Н Ы Е    К О Н С Т А Н Т Ы             */
/*******************************************************************/

// путь к файлу через константный указатель
// Входные файлы
// ТЕСТЫ ДЛЯ МАТРИЦЫ СМЕЖНОСТИ
//const char* FNAMEIN = "matrix_t9_001.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_002.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_003.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_004.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_005.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_006.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_007.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_008.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_009.txt";                // файл с матрицей смежности
const char* FNAMEIN = "matrix_t9_010.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_101.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_102.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_103.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_104.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_105.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_106.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_107.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_108.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_109.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_110.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_111.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_112.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_113.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_114.txt";                // файл с матрицей смежности
//const char* FNAMEIN = "matrix_t9_115.txt";                // файл с матрицей смежности


// ТЕСТЫ ДЛЯ СПИСКА РЕБЕР
//const char* FNAMEIN = "list_of_edges_t9_001.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_002.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_003.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_004.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_005.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_006.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_007.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_008.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_009.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_010.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_101.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_102.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_103.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_104.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_105.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_106.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_107.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_108.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_109.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_110.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_111.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_112.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_113.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_114.txt";         // файл со списком рёбер
//const char* FNAMEIN = "list_of_edges_t9_115.txt";         // файл со списком рёбер


// ТЕСТЫ ДЛЯ СПИСКА СМЕЖНОСТИ
// ТЕСТОВ В АРХИВЕ НЕ ПРЕДСТАВЛЕНО

// ВЫХОДНЫЕ ФАЙЛЫ
const char* FNAMEOUT = "Output_File.txt";

const int INF = 10000;                                      // бесконечность для матрицы расстояний
const int MAX_ITERATIONS = 50;                              // количество циклов прохода
const int NUM_ANTS = 300;                                   // кол-во обычных муравьёв
const int NUM_SPECIAL_ANTS = 50;                            // количество идеальных муравьёв

const double ALPHA = 2.0;                                   // коэффицент, влияющий на учитывание расстояния
const double BETA = 1.0;                                    // коэффицент, влияющий на учитывание феромонов
const double SPECIAL_ANT_FACTOR = 2.0;                      // коэффицент пропорцианальности при вычислении нового феромонового следа

const double INITIAL_PHEROMONE = 1.0;                       // инициализация значения феромона на начальных ребрах.
const double EVAPORATION_FACTOR = 0.5;                      // коэффицент забывания старого пути




/*******************************************************************/
/*      Г Л О Б А Л Ь Н Ы Е    Ф А Й Л О В Ы Е    П О Т О К И      */
/*******************************************************************/

 // объявление объекта для потокового ввода данных из файла
ifstream fin;
// объявление объекта для потокового вывода данных в файл
ofstream fout;




/*******************************************************************/
/*                 И Е Р А Р Х И Я   К Л А С С О В                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // граф в программе представлен матрицей смежности
	int m_size;                                               // размер матрицы смежности (количество вершин в графе)

public:
	// конструктор
	Graph();
	// деструктор
	~Graph();
	// константный геттер для получения значения размера
	const int GetSize();
	// функция возвращающая True, если граф ориентированный, False, если граф простой;
	bool is_directed();
	// функция, возвращающая матрицу смежности
	vector<vector<int>> adjacency_matrix();
	// весовая функция, принимает номера вершин, возвращает вес ребра, связывающего их;
	int Weight(int Vi, int Vj);
	// функция, принимающая номера вершин и возвращает True, если в графе есть соответствующее ребро / дуга, False, если ребра нет;
	bool is_edge(int Vi, int Vj);
	// функция, возвращающая список вершин, смежных вершине v;
	vector<int> adjacency_list(int v);
	// функция, возвращающая список всех рёбер графа;
	vector<pair<int, int>> list_of_edges_pairs();
	// функция, возвращающая список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              П Р О Т О Т И П Ы    Ф У Н К Ц И Й                 */
/*******************************************************************/

// сохранение графа как фотографии
string drawGraph(const vector<vector<int>>& adjacencyMatrix);          // объявление константной ссылки на двумерный вектор adjacencyMatrix, содержащий целочисленные значения 

// вывод графа на экран в виде картинки
void OpenImage(const vector<vector<int>>& adjacencyMatrix);            // объявление константной ссылки на двумерный вектор adjacencyMatrix, содержащий целочисленные значения 

// вывод матрицы смежности на экран
void PrintMatrix(vector<vector<int>> matrix);                          // матрица, которую необходимо вывести на экран. Передача по значению

// печать справки и авторов работы
void Usloviya();

// функция обновления феромонов на пройденном пути
void updateSpecialAntPheromones_my(const vector<int>& antTours,        // вектор, содержащий порядок посещения городов муравьем 
	                               vector<vector<double>>& pheromones, // двумерный вектор с феромонами на ребрах графа
	                               vector<vector<int>>& distances);    // двумерный вектор с расстояниями между городами

// выбор следующего пути для муравья
int selectNextCity(int ant,                                            // номер текущего муравья
	               int currentCity,                                    // текущий город, в котором находится муравей
	               const vector<bool>& visited,                        // вектор, указывающий, какие города уже посещены
	               vector<vector<double>>& pheromones,                 // двумерный массив с уровнем феромонов на ребрах графа
	               vector<vector<int>> distances,                      // двумерный массив с расстояниями между городами
	               vector<bool> perfect_ant);                          // вектор, указывающий, является ли текущий муравей "идеальным"

// функция обхода по графу. Строит маршрут для одного муравья
vector<int> constructTour(int ant,                                     // номер муравья
	                      vector<vector<double>>& pheromones,          // двумерный вектор значений феромонов на ребрах графа
	                      vector<vector<int>> distances,               // двумерный вектор расстояний между городами графа
	                      vector<bool> perfect_ant);                   // вектор булевых значений, указывающих, является ли муравей "идеальным"

// функция построения муравьиных путей
vector<vector<int>> constructAntTours(vector<vector<double>>& pheromones, // двумерный вектор значений феромонов на ребрах графа
	                                  vector<vector<int>> distances,      // двумерный вектор расстояний между городами графа
	                                  vector<bool> perfect_ant);          // вектор булевых значений, указывающих, является ли муравей "идеальным"

// функция поиска лучшего (минимального) пути среди всех муравьёв
vector<int> findBestTour(const vector<vector<int>>& antTours,             // двумерный вектор муравьиных путей
	                     vector<vector<int>> distances);                  // двумерный вектор расстояний между городами

// функция, которая реализует высыхание феромонов после прохода всех муравьёв
void evaporatePheromones(vector<vector<double>>& pheromones,              // двумерный вектор, представляющий матрицу феромонов между городами
	                     vector<vector<int>>& distances);                 // двумерный вектор, представляющий матрицу расстояний между городами

// вывод матрицы  в файл
void PrintMatrToFile(vector<vector<int>> matrix);                         // матрица, которую необходимо вывести в файл. Передача по значению




// конструктор - считывание матрицы из файла
Graph::Graph()
{
	fin.open(FNAMEIN);            // связываем объект с файлом
	if (!fin.is_open())           // файл не найден
	{
		cout << "Файла с таким именем нет. Невозможно осуществить чтение\n";
		fin.close();              // закрыть файл для чтения
		system("pause");
		exit(0);                  // возвращаем значение, соответствующее типу в caller
	}// if (!fin.is_open())

	int value;                    // очередной считываемый символ
	char key;                     // ключ для указания пользователем варианта задания графа в файле
	bool spravka = true;          // ключ для вывода справки на экран
	vector<int> row;              // вектор для считывания промежуточных значений из файла построчно
	vector<vector<int>> matrix;   // вспомогательная матрица смежности

	// повтор ввода задания графа, когда пользователь захотел вывести на экран справку
	while (spravka)
	{
		cout << "\x1b[30m В В Е Д И Т Е   К Л Ю Ч   И Л И   <h>   Д Л Я   В Ы З О В А   П О Д С К А З К И : \x1b[30m";
		// пользователь ввёл ключ для того, чтобы явно указать, каким способом он задал граф
		cin >> key;
		cout << "\n Вы ввели: " << key << endl;

		// в зависимости от значения ключа
		switch (key)
		{
			// работа с матрицей смежности
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   М А Т Р И Ц А   С М Е Ж Н О С Т И\n\n\x1b[30m\n";
			// считываем очередное число из файла
			while (fin >> value)
			{
				// после считывания каждой строки очищаем вектор строки
				row.clear();
				// загоняем в вектор первый считанный элемент от первого while (fin >> value)
				row.push_back(value);
				// считываем все остальные элементы строки, пока не нашли символ её окончания - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// кладем в матрицу считанную строку. Все строки имеют одинаковый размер, так как работаем с матрицей смежности
				m_matrix.push_back(row);

			}// while (fin >> value)

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// работа со списком рёбер
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   С П И С О К   Р Ё Б Е Р\n\n\x1b[30m\n";

			// считываем значения из файла в вектор
			// в векторе будут находиться с чередованием через три элементы: начальная вершина, конечная вершина и вес ребра
			while (fin >> value)
			{
				// после считывания каждой строки очищаем вектор строки
				row.clear();
				// загоняем в вектор первый считанный элемент от первого while (fin >> value)
				row.push_back(value);
				// считываем все остальные элементы строки, пока не нашли символ её окончания - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// кладем в матрицу считанную строку. Все строки имеют одинаковый размер, так как работаем с матрицей смежности
				m_matrix.push_back(row);
			}// while (fin >> value)

			// закрыть файл чтения
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // размер матрицы смежности
			vector<vector<int>> vec_1(size_m);                // матрица смежности

			for (int i = 0; i < size_m; i++)                  // задаём размер каждой ячейки vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// заполняем матрицу смежности
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 элемент - это вес ребра, если он не указан, то значит он = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// запоминаем матрицу смежности
			m_matrix = vec_1;
			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// работаем со списками смежности
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m В Ы   В Ы Б Р А Л И   Т И П   З А Д А Н И Я   -   С П И С О К   С М Е Ж Н О С Т И\n\n\x1b[30m\n";

			// чтение из файла построчно
			string line;
			int rowNumber = 0;            // номер текущей строки

			// чтение построчное
			while (getline(fin, line))
			{
				// Если строка пустая, заполняем текущую строку нулями
				if (line.empty())
				{
					matrix.push_back(vector<int>(m_size, 0));
				}
				// строка не пустая
				else
				{
					// вектор строки
					vector<int> row;
					// создает поток для чтения значений из строки line. Затем мы можем использовать iss вместе с оператором >> для извлечения значений из строки.
					istringstream iss(line);
					// очередная величина для чтения
					int value;

					// читаем значение из файла и помещаем его в вектор строки
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// помещаем строку в матрицу
					matrix.push_back(row);
				}// if (line.empty()) 

				// увеличиваем номер строки
				rowNumber++;
			}// while (getline(fin, line)) 

			// файл прочитан - закрываем его
			fin.close();

			m_size = matrix.size();                         // размер матрицы смежности

			vector<vector<int>> vec_1(m_size);              // доп матрица смежности размером m_size

			for (int i = 0; i < m_size; i++)                // задаём размер каждой ячейки доп матрицы смежности
			{
				// заполняем вспомогательную матрицу нулями по всему размеру
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // заполняем доп матрицу смежности 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// единица в тех столбцах, которые перечислены для данной в файле
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// загоняем значения в основную матрицу смежности
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// повторять ввод не надо. Матрица заполнена
			spravka = false;
			break;
		}

		// пользователь выбрал справку
		case('h'):
		case('H'):
		{
			// повторить ввод после появления мправки на экране
			spravka = true;
			// выводим условия
			Usloviya();
			break;
		}

		// иначе - пользователь ввёл не тот ключ. Заканчиваем программу с ошибкой
		default:
			cout << "\n\x1b[31m ПЕРЕЗАПУСТИТЕ ПРОГРАММУ И ВВЕДИТЕ ЗНАЧЕНИЕ ИЗ СПИСКА КЛЮЧЕЙ!!!\n\x1b[30m";
			// закрываем файл считывания
			fin.close();
			exit(0);
		}
	}
	// закрываем файл считывания
	fin.close();
	// запоминаем размер считанной/ преобразованной матрицы смежности
	m_size = m_matrix.size();
}

// деструктор
Graph::~Graph()
{
	// пустое тело - векторы уничтожаются автоматически
}

// геттер для получения значения размера
const int Graph::GetSize()
{
	// возвращаем значение размера матрицы
	return(m_size);
}


// функция возвращающая True, если граф ориентированный, False, если граф простой;
bool Graph::is_directed()
{
	// идём по строкам
	for (int i = 0; i < m_size; i++)
	{
		// идём по столбцам
		for (int j = 0; j < m_size; j++)
		{
			// если граф неориентированный, то матрица симметрична, так как по ребру можно пройти подвум направлениям
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // Найдено направленное ребро - граф ориентированный
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // Не найдено направленных ребер - граф неориентированный
}


// функция, возвращающая матрицу смежности
vector<vector<int>> Graph::adjacency_matrix()
{
	return(m_matrix);
}


// весовая функция, принимает номера вершин, возвращает вес ребра, связывающего их;
int Graph::Weight(int Vi, int Vj)

{
	// номера вершин вышли за диапазоны допустимых значений
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "Ошибка! Такой вершины не существует\n";
		// вернули ошибку
		return(-1);
	}// if

	// если путь существует(в матрице смежности не 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "Вес ребра между вершинами " << Vi << " и " << Vj << " равен" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// возвращаем вес ребра между вершинами
		return(m_matrix[Vi][Vj]);
	}// if

	// граф ориентированный. Выводим вес дуги
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "Граф ориентированный. Дуга есть. Направление учитывается. Вес дуги между вершинами " << Vi << " и " << Vj << " равен" << m_matrix[Vi][Vj] << endl;
		// возвращаем вес дуги
		return(m_matrix[Vi][Vj]);
	}// else if

	// ребра между вершинами нет - элемент матрицы смежности равен 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "Ребра между вершинами " << Vi << " и " << Vj << "нет\n";
		// Вернули нулевое значение
		return(m_matrix[Vi][Vj]);
	}// else if

	return(0);
}


// функция, принимающая номера вершин и возвращает True, если в графе есть соответствующее ребро / дуга, False, если ребра нет;
bool Graph::is_edge(int Vi, int Vj)
{
	// номера вершин вышли за диапазоны допустимых значений - дуги нет
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// вернули, что дуги нет
		return(false);
	}// if

	// элемент матрицы смежности не равен 0 - ребро есть
	if (m_matrix[Vi][Vj] != 0)
	{
		// подтверждаем, что ребро есть
		return(true);
	}// if

	// элемент матрицы смежности нулевой - ребра нет
	if (m_matrix[Vi][Vj] == 0)
	{
		// подтверждаем, что ребра нет
		return(false);
	}// if

}


// функция, возвращающая список вершин, смежных вершине v;
vector<int> Graph::adjacency_list(int v)
{
	// список вершин
	vector<int> adjList;

	// Проходим по всем вершинам и проверяем, есть ли ребро между вершиной v и текущей вершиной
	for (int i = 0; i < m_size; i++)
	{
		// путь есть - элемент матрицы не нулевой
		if (m_matrix[v][i] != 0)
		{
			// помещаем вершину в список
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// Возвращаем список смежных вершин
	return adjList;
}


// функция, возвращающая список всех рёбер графа;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// вектор пар, содержащий ребро в виде двух инцидентных ему вершин
	vector<pair<int, int>> edges_pairs;
	// идём по всем элементам строки
	for (int i = 0; i < m_size; i++)
	{
		// идём по всем элементам столбца
		for (int j = 0; j < m_size; j++)
		{
			// если элемент не нулевой
			if (m_matrix[i][j] != 0)
			{
				// загрузили пару вершин
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i

	// вернули вектор рёбер (пар вершин)
	return(edges_pairs);
}


// функция, возвращающая список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // вектор пар вершин(вектор рёбер)
	vector<pair<int, int>> edges_inc;     // вектор рёбер инцидентных вершине v / исходящих из вершины v
	edges = list_of_edges_pairs();        // получаем все пары вершин графа

	// обходим эти пары. Если граф неориентированный, то там будет пара (v,n) и (n, v) - достаточно рассмотреть для инцидентности первый элемент. В орграфе - исходящий элемент всегда первый
	for (int i = 0; i < edges.size(); i++)
	{
		// рассматриваем первый элемент пары
		if (edges[i].first == v)
		{
			// помещаем в списо ребер, инцидентных вершине данное ребро
			edges_inc.push_back(edges[i]);
			// увеличиваем счётчик
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// возвращаем  список всех рёбер графа, инцидентных вершине v / исходящих из вершины v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                Функции               */
/*--------------------------------------*/

// сохранение графа как фотографии
string drawGraph(const vector<vector<int>>& adjacencyMatrix)
{
	// Проверяем размер матрицы смежности. Если больше 25, то считаем ее слишком большой
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// Проверяем наличие весов на ребрах, чтобы понять, нужно ли указывать их при выводе
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// Если вес ребра больше 1 или отрицательный, значит, нужно указывать вес в выводе
				if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
					key = true;
			}
		}

		// Открываем файл для записи графа в формате DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// Выводим граф с указанием весов ребер
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Проверяем, что вес ребра не равен 0, чтобы не выводить ненужные ребра
					if (adjacencyMatrix[i][j] != 0)
					{
						// Выводим ребро с указанием веса в формате DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// Выводим граф без указания весов ребер
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// Проверяем, что вес ребра равен 1, чтобы не выводить ненужные ребра
					if (adjacencyMatrix[i][j] == 1)
					{
						// Выводим ребро без указания веса в формате DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// Закрываем файл и сохраняем результаты
		file << "}" << std::endl;
		file.close();

		// Генерируем изображение графа в формате PNG с помощью утилиты DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// Выводим, что граф большой для рисования
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}// if

	// возвращаем картинку для открытия силами OpenCV
	return "graph.png";
}


// вывод графа на экран
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// Проверяем размерность матрицы смежности
	if (adjacencyMatrix.size() <= 19)
	{
		// Получаем путь к изображению, созданному с помощью функции drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// Загружаем изображение с помощью OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// Проверяем, удалось ли загрузить изображение
		if (img.empty())
		{
			cout << "Could not open or find the image" << endl;
			return;
		}// if

		// Создаем окно с названием "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// Показываем изображение в окне
		cv::imshow("Graph", img);
		// Ждем, пока пользователь нажмет любую клавишу
		cv::waitKey(0);
		// Закрываем окно
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
}


// вывод матрицы смежности на экран
void PrintMatrix(vector<vector<int>> matrix)
{
	// отключаем русский язык
	setlocale(0, "C");            // выводим массив в красивых скобках
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // вывод верхних квадратных скобок

	// идём по строкам
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// идём по столбцам
		for (int j = 0; j < matrix.size(); j++)
		{
			// выводим элемент матрицы
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // вывод верхних квадрат
	// подключаем русский язык
	setlocale(LC_ALL, "Russian");

	// возвращаем обещанное значение
	return;
}


// печать справки и авторов работы
void Usloviya()
{
	cout << "\n\t\t\t\t/*******************************************************************************\n";
	cout << "\t\t\t\t* Л А Б О Р А Т О Р Н А Я   Р А Б О Т А  №9  З А   5   С Е М Е С Т Р   С  +  +   *\n";
	cout << "\t\t\t\t*--------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                      *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab10                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab10. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : Викулов Д.Г.                                                   *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                                *\n";
	cout << "\t\t\t\t* Created       : 10/10/23                                                       *\n";
	cout << "\t\t\t\t* Last Revision : 22/10/23                                                       *\n";
	cout << "\t\t\t\t**********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   С П Р А В К А : \n\n\x1b[30m";
	// Выводим условия в таблице
	setlocale(0, "C");                       // отключаем русский язык
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // выводим верхнюю строку шапки
	setlocale(LC_ALL, "Rus");                // подключаем русский язык
	cout << " Выберите одно значние из списка:      ";
	setlocale(0, "C");                       // отключаем русский язык
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // выводим нижнюю строку шапки с разделителем между номером и названием алгоритма
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // выводим условия выбора и нижнюю с боковыми строчками таблицы
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // подключаем русский язык

	return;                                 // возвращаем обещанное значение
}


// функция обновления феромонов на пройденном пути
void updateSpecialAntPheromones_my(const vector<int>& antTours,        // вектор, содержащий порядок посещения городов муравьем 
	                               vector<vector<double>>& pheromones, // двумерный вектор с феромонами на ребрах графа
	                               vector<vector<int>>& distances)     // двумерный вектор с расстояниями между городами
{
	double tourLength = 0.0;                                           // переменная, хранящая длину пути муравья

	// цикл суммирования расстояния пути следования муравья
	// вычисляем длину пути муравья, пройденного в соответствии с antTours
	for (int i = 0; i < antTours.size() - 1; i++)
	{
		int city1 = antTours[i];
		int city2 = antTours[i + 1];
		tourLength = tourLength + distances[city1][city2];             // общая длина пути 
	}// for i

	// цикл обновления феромонов, где происходит умножение ферромона на коэффициент высыхания и добавление величины, обратной расстоянию на коэффицент пропорцианальности при вычислении нового феромонового следа
	for (int i = 0; i < distances.size() - 1; i++)
	{
		// получаем пурвую вершину ребра пути
		int city1 = antTours[i];
		// получаем вторую вершину ребра пути
		int city2 = antTours[i + 1];

		// умножаем ферромон на ребре на коэффициент забыывания и суммируем коэффициент пропорциональности, делённый на расстояние
		pheromones[city1][city2] = pheromones[city1][city2] * (1.0 - EVAPORATION_FACTOR) + SPECIAL_ANT_FACTOR / tourLength;
		pheromones[city2][city1] = pheromones[city2][city1] * (1.0 - EVAPORATION_FACTOR) + SPECIAL_ANT_FACTOR / tourLength; // так как не ориентированный граф. Сохраняем симметричное значение в матрицу
	}// for i

	// вернули обещанное значение
	return;
}


// выбор следующего пути для муравья
int selectNextCity(int ant,                                            // номер текущего муравья
	               int currentCity,                                    // текущий город, в котором находится муравей
	               const vector<bool>& visited,                        // вектор, указывающий, какие города уже посещены
	               vector<vector<double>>& pheromones,                 // двумерный массив с уровнем феромонов на ребрах графа
	               vector<vector<int>> distances,                      // двумерный массив с расстояниями между городами
	               vector<bool> perfect_ant)                           // вектор, указывающий, является ли текущий муравей "идеальным"
{
	
	double total = 0.0;                                                // вспомогательная переменная для суммирования значений в знаменателе формулы (все допустимые города)
	vector<double> probabilities(distances.size(), 0.0);               // вектор, в котором хранятся вероятности перехода в какую-то вершину

	// проходим по всем городам (вершинам матрицы смежности)
	for (int city = 0; city < distances.size(); city++)
	{
		// если вершина ещё не посещена и в неё есть путь, то 
		if (!visited[city] && distances[currentCity][city] != 0)
		{
			double pheromone = pow(pheromones[currentCity][city], ALPHA);    // вычисление величины феромона в степени  ALPHA
			double distance = pow(1.0 / distances[currentCity][city], BETA); // вычисление величины обратной расстонияю в степени BETA
			probabilities[city] = pheromone * distance;                      // вычисление числителя, для нахождения вероятности прохода муравья
			total = total + probabilities[city];                             // суммирование знаменателя ( вычисление общей вероятности, которая в итоге должна дать 1)
		}// if

	}// for city


	double random = static_cast<double>(rand()) / RAND_MAX;                  // инициализируется переменная random, которая содержит случайное число от 0 до 1.Для этого используется функция rand(), которая возвращает случайное целое число,
	// затем это число преобразуется в диапазоне от 0 до 1 с помощью деления на RAND_MAX и приведения к типу double.
	double cumulativeProbability = 0.0;                                      // переменная, хранящая общую вероятность
	double chance = 0;                                                       // переменная для хранения вероятности
	int c_city = -1;                                                         // переменная для хранения найденной вершины, в которую пойдёт муравей

	// если это - обычный муравей
	if (!perfect_ant[ant])
	{
		// проход по всем вершинами графа
		for (int city = 0; city < distances.size(); city++)
		{
			// если вершина ещё не посещена и в неё есть путь, то 
			if (!visited[city] && distances[currentCity][city] != 0)
			{
				// суммирование вероятностей (вероятность получается делением ранее вычисленных числителей и знаменателей. На 100 мы не умножали -> случайное число в диапазоне от 0 до 1
				cumulativeProbability = cumulativeProbability + probabilities[city] / total;
				// Когда суммарная вероятность превышает или становится равной random, выбирается город с соответствующей вероятностью. 
				// Это дает шанс исследовать разные маршруты и избежать застревания в локальных оптимумах.
				if (random <= cumulativeProbability)
				{
					// возвращаем город, в который идёт муравей
					return city;
				}// if

			}// if

		}// for city

	}// if

	// если это - идеальный муравей
	else if (perfect_ant[ant])
	{
		// проход по всем вершинами графа
		for (int city = 0; city < distances.size(); city++)
		{
			// поиск среди непосещённых вершин 
			if (!visited[city] && distances[currentCity][city] != 0)
			{
				// функция выбирает город с наибольшей вероятностью из доступных городов и возвращается его номер.
				if (chance < probabilities[city] / total) 
				{
					chance = probabilities[city] / total;  // вычисление вероятности
					c_city = city;                         // запоминаем найденную вершину
				}// if

			}// if

		}// for city

	    // возвращаем вершину, вероятность прохода по которой наибольшая - следующий город для идеального муравья
		return c_city;
	}// else if

	// иначе - нового города для посещения муравьем нет. Он всё посетил
	return -1;
}


// функция обхода по графу. Строит маршрут для одного муравья
vector<int> constructTour(int ant,                                     // номер муравья
	                      vector<vector<double>>& pheromones,          // двумерный вектор значений феромонов на ребрах графа
	                      vector<vector<int>> distances,               // двумерный вектор расстояний между городами графа
	                      vector<bool> perfect_ant)                    // вектор булевых значений, указывающих, является ли муравей "идеальным"
{

	vector<bool> visited(distances.size(), false);                     // вектор отслеживает посещение городов. Сначала все вершины не посещены
	int currentCity;                                                   // переменная, хранящая текущую вершину
	int a;                                                             // вспомогательная переменная, хранящая вершину, с которой муравей начал свой путь 

	// определение текущего города, от которого стартует муравей.
	// если кол-во муравьёв (в данном случае смотрится по номеру муравья) будет больше кол-ва вершин, то муравьи будут заново проходить по вершинами графа
	if (ant > distances.size() - 1)
	{
		// Если номер муравья (ant) превышает количество городов, то текущий город устанавливается как ant по модулю количества городов
		currentCity = ant % distances.size();                          // берём остаток от деления номера муравья на размер матрицы смежности
		a = currentCity;
	}

	// иначе текущий город равен ant
	else
	{
		currentCity = ant;
		a = currentCity;
	}// if

	// пометка текущего города как посещенного и добавление его в маршрут
	visited[currentCity] = true;                                      // выбранная вершина является посещённой (в ней находится муравей)
	vector<int> tour;                                                 // вектор обхода, в который будут помещатся вершины через которые мы проходим
	tour.push_back(currentCity);                                      // кладём начальную вершину в вектор обхода

	// пока количество вершин в векторе не будет равно количество вершин в графе (в задаче коммивояжера все вершины должны быть посещены) 
	while (tour.size() < distances.size())
	{
		// выбрали вершину, в которую нужно идти текущему муравью
		int nextCity = selectNextCity(ant, currentCity, visited, pheromones, distances, perfect_ant);

		// Если найден следующий город (nextCity) и он еще не был посещен, он добавляется в маршрут, помечается как посещенный, и
		// текущий город обновляется на новый
		if (nextCity != -1)
		{
			tour.push_back(nextCity);                                // кладём новую вершину в вектор
			visited[nextCity] = true;                                // помечаем её как посещённую
			currentCity = nextCity;                                  // обновляем текущий город на новый
		}// if

	}// while

	// Проверка наличия пути от текущего города обратно к исходному городу, с которого начался обход.
	// Если связь существует, исходный город добавляется в маршрут.
	if (distances[currentCity][a] != 0)
	{
		tour.push_back(a);
	}// if

	// обновление феромонового следа на пути следования муравья
	updateSpecialAntPheromones_my(tour, pheromones, distances);

	// вернуть построенный маршрут в виде вектора целых чисел
	return tour;
}


// функция построения муравьиных путей
vector<vector<int>> constructAntTours(vector<vector<double>>& pheromones, // двумерный вектор значений феромонов на ребрах графа
	                                  vector<vector<int>> distances,      // двумерный вектор расстояний между городами графа
	                                  vector<bool> perfect_ant)           // вектор булевых значений, указывающих, является ли муравей "идеальным" 
{
	vector<vector<int>> antTours;                                         // матрица, хранящая муравьиные пути

	// В цикле по каждому муравью, от 0 до NUM_ANTS, вызывается функция constructTour для создания муравьиного пути для текущего муравья
	for (int ant = 0; ant < NUM_ANTS; ant++)                                        // цикл по муравьям
	{
		vector<int> tour = constructTour(ant, pheromones, distances, perfect_ant);  // построения пути одним муравьём
		antTours.push_back(tour);                                                   // заталкивание этого пути в матрицу путей
	}// for ant

	// возвращается матрица antTours, содержащая все построенные муравьиные пути
	return antTours;
}


// функция поиска лучшего (минимального) пути среди всех муравьёв
vector<int> findBestTour(const vector<vector<int>>& antTours,             // двумерный вектор муравьиных путей
	                     vector<vector<int>> distances)                   // двумерный вектор расстояний между городами
{
	vector<int> bestTour;                                                 // вектор, хранящий лучший путь
	double bestlen = INF;                                                 // переменная, хранящая сумму минимального размера пути
	double len = 0;                                                       // хранение суммы веса пути муравья

	// В цикле по каждому муравьиному пути в antTours
	for (int i = 0; i < antTours.size(); i++)
	{
		// проходим по каждому городу в пути, начиная со второго города
		for (int j = 1; j < antTours[i].size(); j++)
		{
			// cуммируем веса ребер между текущим городом и предыдущим городом
			len = len + distances[antTours[i][j - 1]][antTours[i][j]];
		}// for j

		// нахождение минимального пути среди всех муравьиных путей
		// если значение len меньше текущего значения bestlen, то обновляем bestlen и сохраняем текущий путь в bestTour
		if (bestlen > len)
		{
			bestlen = len;
			bestTour = antTours[i];
		}// if

		// обнуляем переменную len для последующего расчета веса следующего пути
		len = 0; // обнуление счётчика пути

	}// for i

	// возвращаем вектор bestTour, содержащий лучший путь среди всех муравьиных путей
	return bestTour;
}


// функция, которая реализует высыхание феромонов после прохода всех муравьёв
void evaporatePheromones(vector<vector<double>>& pheromones,              // двумерный вектор, представляющий матрицу феромонов между городами
	                     vector<vector<int>>& distances)                  // двумерный вектор, представляющий матрицу расстояний между городами
{
	// во внешнем цикле перебираются все строки матрицы феромонов pheromones
	for (int i = 0; i < distances.size(); i++)
	{
		// во внутреннем цикле перебираются все столбцы матрицы феромонов pheromones
		for (int j = 0; j < distances.size(); j++)
		{
			// умножение феромона на коэф высыхания
			pheromones[i][j] = pheromones[i][j] * (1.0 - EVAPORATION_FACTOR);
		}// for j

	}// for i
}


// вывод матрицы  в файл
void PrintMatrToFile(vector<vector<int>> matrix)                 // матрица, которую необходимо вывести в файл. Передача по значению
{
	// идём по строкам матрицы
	for (int i = 0; i < matrix.size(); i++)
	{
		// идём по столбцам матрицы
		fout << " ";
		for (int j = 0; j < matrix.size(); j++)
		{
			// выводим очередной элемент матрицы в файл
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// возвращаем обещанное значение
	return;
}




/*------------------------------------------------------------------------*/
/*            Главная функция           */
/*--------------------------------------*/
int main()
{
	// подключаем русский язык
	setlocale(LC_ALL, "Russian");
	// цвет консоли - белый
	system("color F0");
	// флаг печати в файл. Изначально - печати нет
	bool print = false;
	// ключ, введённый пользователем для печати
	char letter;

	cout << "\t\t\t\t\t\t\x1b[34m    Р А Б О Т А   С   Г Р А Ф А М И\x1b[30m\n\n\n";
	// создали объект графа. Конструктор применился по-умолчанию
	Graph NewGraph;

	// Выбор, хочет ли пользователь выводить в файл вычесленную информацию
	cout << " Хотите ли Вы выводить данные в файл? Введите <o>, если хотите, или любой другой символ - если нет. Введите: ";
	cin >> letter;                             // ввод пользователем
	cout << "\n Вы ввели: " << letter;         // эхо-печать

	// Если пользователь хочет печатать. Устанавливаем флаг
	if (letter == 'o' || letter == 'O')
	{
		print = true;

	}// if (letter == 'o' || letter == 'O')


	// Выводим матрицу смежности по данным из файла на экран
	cout << "\n\n\t\t\t\t\x1b[35m    М А Т Р И Ц А   С М Е Ж Н О С Т И   П О   И С Х О Д Н Ы М   Д А Н Н Ы М :\x1b[30m\n\n";
	PrintMatrix(NewGraph.adjacency_matrix());

	vector<vector<double>> pheromones(NewGraph.GetSize());        // матрица феромонов, которые находятся на каждом ребре
	vector<vector<int>> m_matrix = NewGraph.adjacency_matrix();   // матрица смежности графа - матрица городов и расстояний между ними
	
	// заполняем матрицу феромонов значениями 0
	for (int i = 0; i < pheromones.size(); i++)
    {
        pheromones[i].resize(m_matrix.size(), 0);
    }// for i

	// инициализация феромонов
	// идём по всем строкам матрицы смежности
	for (int i = 0; i < m_matrix.size(); i++)
	{
		// идём по всем столбцам матрицы смежности
		for (int j = 0; j < m_matrix.size(); j++)
		{
			// если значение m_matrix[i][j] не равно 0, устанавливается значение INITIAL_PHEROMONE в соответствующую ячейку матрицы pheromones
			if (m_matrix[i][j] != 0)
			{
				// помечаем существующие рёбра начальными значениями феромона
				pheromones[i][j] = INITIAL_PHEROMONE;
			}// if

		}// for j

	}// for i

	// вектор, который показывает идеальных муравьёв 
	vector<bool> perfect_ant(NUM_ANTS, false);

	// пусть первые NUM_SPECIAL_ANTS муравьёв  - не идеальные, остальные - идеальные 
	for (int i = NUM_SPECIAL_ANTS; i < NUM_ANTS; i++)
	{
		perfect_ant[i] = true;
	}// for i


	vector<vector<int>> antTours;     // матрица путей муравьёв
	vector<int> bestTour;             // вектор, хранящий лучший путь
	vector<int> min_tour;             // вектор, хранящий вес минимального пути
	int min = INF;                    // переменная, хранящая min
	int sum = 0;                      // промежуточная переменная хранения суммы рёбер в пути

	// цикл по количеству повторений 
	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		antTours = constructAntTours(pheromones, m_matrix, perfect_ant);   // построние путей следования муравьёв
	    bestTour = findBestTour(antTours, m_matrix);                       // нахождение лучшего пути

		// нахождение расстояния лучшего пути на данном повторении
		for (int j = 1; j < bestTour.size(); j++)
		{
			// суммируем веса всех рёбер, входящих в данный путь
			sum = sum + m_matrix[bestTour[j]][bestTour[j - 1]];
		}// for j

		// поиск минимального пути среди всех повторений следований муравьёв
		if (min > sum)
		{
			min = sum;
			min_tour = bestTour;
		}// if

		// вызывается функция evaporatePheromones, которая применяет процесс высыхания феромонов на каждом ребре графа, используя матрицы pheromones и m_matrix
		evaporatePheromones(pheromones, m_matrix);

		// следующая итерация цикла
	    sum = 0;                // обнуление суммы
		antTours.clear();       // очистка матрицы путей муравьёв
		bestTour.clear();       // очистка вектора с лучшим муравьиным путем на данном повторении

	}// for i

	cout << "\n\t\t\t\t\t\x1b[31m       А Л Г О Р И Т М   М У Р А В Ь И Н О Й   К О Л О Н И И :\x1b[30m\n\n";

	// вывод веса лучшего муравьиного пути
	cout << "\x1b[36m Гамильтонов цикл имеет длину \x1b[30m" << min << endl << endl;

	// вывод лучшего муравьиного пути
	// идём по элементам лучшего пути
	for (int i = 0; i < min_tour.size()-1; i++)
	{
		// выводим вершины в порядке следования
		cout << " " << min_tour[i] + 1 << " - " << min_tour[i + 1] + 1 << " : " << NewGraph.adjacency_matrix()[min_tour[i]][min_tour[i + 1]];
		cout << endl;
	}// for i

	// вывод в файл
	if (print)
	{
		fout.open(FNAMEOUT);           // связываем объект с файлом
		if (!fout.is_open())           // файл не найден
		{
			cout << "Файла с таким именем нет. Невозможно осуществить чтение";
			fin.close();               // закрыть файл для чтения
			system("pause");
			exit(0);                   // возвращаем значение, соответствующее типу в caller
		}// if (!fout.is_open())

		fout << "\t\t\t\t\t\t    Р А Б О Т А   С   Г Р А Ф А М И";
		fout << "\n\n М А Т Р И Ц А   С М Е Ж Н О С Т И   П О   И С Х О Д Н Ы М   Д А Н Н Ы М :\n\n";
		// выводим матрицу смежности в файл
		PrintMatrToFile(NewGraph.adjacency_matrix());

		fout << "\n А Л Г О Р И Т М   М У Р А В Ь И Н О Й   К О Л О Н И И :\n\n";

		// вывод веса лучшего муравьиного пути
		fout << " Гамильтонов цикл имеет длину " << min << endl << endl;

		// вывод лучшего муравьиного пути
		// идём по элементам лучшего пути
		for (int i = 0; i < min_tour.size() - 1; i++)
		{
			// выводим вершины в порядке следования
			fout << " " << min_tour[i] + 1 << " - " << min_tour[i + 1] + 1 << " : " << NewGraph.adjacency_matrix()[min_tour[i]][min_tour[i + 1]];
			fout << endl;
		}// for i
	}// if

	// Выводим картинку с графом на экран
	OpenImage(NewGraph.adjacency_matrix());
	// закрываем файл для записи
	fin.close();
	// возвращаем обещанное значение в функцию
	return 0;
}