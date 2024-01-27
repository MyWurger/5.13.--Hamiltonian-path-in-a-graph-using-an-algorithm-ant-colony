/********************************************************************************
 * � � � � � � � � � � � �   � � � � � �  �9  � �   5   � � � � � � �   �  +  + *
 *------------------------------------------------------------------------------*
 * Project Type  : Win64 Console Application                                    *
 * Project Name  : Teor_Grph_Lab9                                               *
 * File Name     : Lab9. CPP                                                    *
 * Programmer(s) : ������� �.�.                                                 *
 * Modifyed By   :                                                              *
 * Created       : 10/10/23                                                     *
 * Last Revision : 22/10/23                                                     *
 * Comment(s)    : ���������, ��������� ����������� ���� � ����� ��� ������     *
 *                 ��������� ���������� �������. ����������� ������ ��������    *
 *                 �������, �������� ������� ����                              *
 ********************************************************************************/


#include <iostream>              // ����������� ������ �����/������
#include <vector>                // ������ � ��������� ��� �������� �������� ���������� � �������� ���������
#include <fstream>               // ������ � �������� �����/������ ��� �����
#include <iomanip>               // ���������� � ������������� setw
#include <graphviz/gvc.h>        // ���������� Graphviz ��� ������������ ����������� ����� �� ������� ���������
#include <opencv2/opencv.hpp>    // ���������, ������������� ��� ������� OpenCv

using namespace std;             // ���������� ������������ ��� std


/*******************************************************************/
/*            � � � � � � � � � �    � � � � � � � � �             */
/*******************************************************************/

// ���� � ����� ����� ����������� ���������
// ������� �����
// ����� ��� ������� ���������
//const char* FNAMEIN = "matrix_t9_001.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_002.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_003.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_004.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_005.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_006.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_007.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_008.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_009.txt";                // ���� � �������� ���������
const char* FNAMEIN = "matrix_t9_010.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_101.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_102.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_103.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_104.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_105.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_106.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_107.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_108.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_109.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_110.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_111.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_112.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_113.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_114.txt";                // ���� � �������� ���������
//const char* FNAMEIN = "matrix_t9_115.txt";                // ���� � �������� ���������


// ����� ��� ������ �����
//const char* FNAMEIN = "list_of_edges_t9_001.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_002.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_003.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_004.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_005.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_006.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_007.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_008.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_009.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_010.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_101.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_102.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_103.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_104.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_105.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_106.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_107.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_108.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_109.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_110.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_111.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_112.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_113.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_114.txt";         // ���� �� ������� ����
//const char* FNAMEIN = "list_of_edges_t9_115.txt";         // ���� �� ������� ����


// ����� ��� ������ ���������
// ������ � ������ �� ������������

// �������� �����
const char* FNAMEOUT = "Output_File.txt";

const int INF = 10000;                                      // ������������� ��� ������� ����������
const int MAX_ITERATIONS = 50;                              // ���������� ������ �������
const int NUM_ANTS = 300;                                   // ���-�� ������� ��������
const int NUM_SPECIAL_ANTS = 50;                            // ���������� ��������� ��������

const double ALPHA = 2.0;                                   // ����������, �������� �� ���������� ����������
const double BETA = 1.0;                                    // ����������, �������� �� ���������� ���������
const double SPECIAL_ANT_FACTOR = 2.0;                      // ���������� ������������������ ��� ���������� ������ ������������ �����

const double INITIAL_PHEROMONE = 1.0;                       // ������������� �������� �������� �� ��������� ������.
const double EVAPORATION_FACTOR = 0.5;                      // ���������� ��������� ������� ����




/*******************************************************************/
/*      � � � � � � � � � �    � � � � � � � �    � � � � � �      */
/*******************************************************************/

 // ���������� ������� ��� ���������� ����� ������ �� �����
ifstream fin;
// ���������� ������� ��� ���������� ������ ������ � ����
ofstream fout;




/*******************************************************************/
/*                 � � � � � � � �   � � � � � � �                 */
/*******************************************************************/

/*------------------------------------------------------------------------*/
/*                 Graph                  */
/*----------------------------------------*/

class Graph
{
private:
	vector<vector<int>> m_matrix;                             // ���� � ��������� ����������� �������� ���������
	int m_size;                                               // ������ ������� ��������� (���������� ������ � �����)

public:
	// �����������
	Graph();
	// ����������
	~Graph();
	// ����������� ������ ��� ��������� �������� �������
	const int GetSize();
	// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
	bool is_directed();
	// �������, ������������ ������� ���������
	vector<vector<int>> adjacency_matrix();
	// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
	int Weight(int Vi, int Vj);
	// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
	bool is_edge(int Vi, int Vj);
	// �������, ������������ ������ ������, ������� ������� v;
	vector<int> adjacency_list(int v);
	// �������, ������������ ������ ���� ���� �����;
	vector<pair<int, int>> list_of_edges_pairs();
	// �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	vector<pair<int, int>> list_of_edges(int v);
};




/*******************************************************************/
/*              � � � � � � � � �    � � � � � � �                 */
/*******************************************************************/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix);          // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ����� �� ����� � ���� ��������
void OpenImage(const vector<vector<int>>& adjacencyMatrix);            // ���������� ����������� ������ �� ��������� ������ adjacencyMatrix, ���������� ������������� �������� 

// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix);                          // �������, ������� ���������� ������� �� �����. �������� �� ��������

// ������ ������� � ������� ������
void Usloviya();

// ������� ���������� ��������� �� ���������� ����
void updateSpecialAntPheromones_my(const vector<int>& antTours,        // ������, ���������� ������� ��������� ������� �������� 
	                               vector<vector<double>>& pheromones, // ��������� ������ � ���������� �� ������ �����
	                               vector<vector<int>>& distances);    // ��������� ������ � ������������ ����� ��������

// ����� ���������� ���� ��� �������
int selectNextCity(int ant,                                            // ����� �������� �������
	               int currentCity,                                    // ������� �����, � ������� ��������� �������
	               const vector<bool>& visited,                        // ������, �����������, ����� ������ ��� ��������
	               vector<vector<double>>& pheromones,                 // ��������� ������ � ������� ��������� �� ������ �����
	               vector<vector<int>> distances,                      // ��������� ������ � ������������ ����� ��������
	               vector<bool> perfect_ant);                          // ������, �����������, �������� �� ������� ������� "���������"

// ������� ������ �� �����. ������ ������� ��� ������ �������
vector<int> constructTour(int ant,                                     // ����� �������
	                      vector<vector<double>>& pheromones,          // ��������� ������ �������� ��������� �� ������ �����
	                      vector<vector<int>> distances,               // ��������� ������ ���������� ����� �������� �����
	                      vector<bool> perfect_ant);                   // ������ ������� ��������, �����������, �������� �� ������� "���������"

// ������� ���������� ���������� �����
vector<vector<int>> constructAntTours(vector<vector<double>>& pheromones, // ��������� ������ �������� ��������� �� ������ �����
	                                  vector<vector<int>> distances,      // ��������� ������ ���������� ����� �������� �����
	                                  vector<bool> perfect_ant);          // ������ ������� ��������, �����������, �������� �� ������� "���������"

// ������� ������ ������� (������������) ���� ����� ���� ��������
vector<int> findBestTour(const vector<vector<int>>& antTours,             // ��������� ������ ���������� �����
	                     vector<vector<int>> distances);                  // ��������� ������ ���������� ����� ��������

// �������, ������� ��������� ��������� ��������� ����� ������� ���� ��������
void evaporatePheromones(vector<vector<double>>& pheromones,              // ��������� ������, �������������� ������� ��������� ����� ��������
	                     vector<vector<int>>& distances);                 // ��������� ������, �������������� ������� ���������� ����� ��������

// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix);                         // �������, ������� ���������� ������� � ����. �������� �� ��������




// ����������� - ���������� ������� �� �����
Graph::Graph()
{
	fin.open(FNAMEIN);            // ��������� ������ � ������
	if (!fin.is_open())           // ���� �� ������
	{
		cout << "����� � ����� ������ ���. ���������� ����������� ������\n";
		fin.close();              // ������� ���� ��� ������
		system("pause");
		exit(0);                  // ���������� ��������, ��������������� ���� � caller
	}// if (!fin.is_open())

	int value;                    // ��������� ����������� ������
	char key;                     // ���� ��� �������� ������������� �������� ������� ����� � �����
	bool spravka = true;          // ���� ��� ������ ������� �� �����
	vector<int> row;              // ������ ��� ���������� ������������� �������� �� ����� ���������
	vector<vector<int>> matrix;   // ��������������� ������� ���������

	// ������ ����� ������� �����, ����� ������������ ������� ������� �� ����� �������
	while (spravka)
	{
		cout << "\x1b[30m � � � � � � �   � � � �   � � �   <h>   � � �   � � � � � �   � � � � � � � � � : \x1b[30m";
		// ������������ ��� ���� ��� ����, ����� ���� �������, ����� �������� �� ����� ����
		cin >> key;
		cout << "\n �� �����: " << key << endl;

		// � ����������� �� �������� �����
		switch (key)
		{
			// ������ � �������� ���������
		case('m'):
		case('M'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";
			// ��������� ��������� ����� �� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);

			}// while (fin >> value)

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������ �� ������� ����
		case('e'):
		case('E'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � �\n\n\x1b[30m\n";

			// ��������� �������� �� ����� � ������
			// � ������� ����� ���������� � ������������ ����� ��� ��������: ��������� �������, �������� ������� � ��� �����
			while (fin >> value)
			{
				// ����� ���������� ������ ������ ������� ������ ������
				row.clear();
				// �������� � ������ ������ ��������� ������� �� ������� while (fin >> value)
				row.push_back(value);
				// ��������� ��� ��������� �������� ������, ���� �� ����� ������ � ��������� - \n
				while (fin.peek() != '\n' && fin >> value)
				{
					row.push_back(value);
				}// while (fin.peek() != '\n' && fin >> value)

				// ������ � ������� ��������� ������. ��� ������ ����� ���������� ������, ��� ��� �������� � �������� ���������
				m_matrix.push_back(row);
			}// while (fin >> value)

			// ������� ���� ������
			fin.close();
			int size_m = m_matrix[m_matrix.size() - 1][0];    // ������ ������� ���������
			vector<vector<int>> vec_1(size_m);                // ������� ���������

			for (int i = 0; i < size_m; i++)                  // ����� ������ ������ ������ vec_1
			{
				vec_1[i].resize(size_m, 0);
			}// for i

			// ��������� ������� ���������
			for (int i = 0; i < m_matrix.size(); i++)
			{
				if (m_matrix[0].size() == 3)                  // 3 ������� - ��� ��� �����, ���� �� �� ������, �� ������ �� = 1
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = m_matrix[i][2];
				}
				else
				{
					vec_1[m_matrix[i][0] - 1][m_matrix[i][1] - 1] = 1;
				}// if (m_matrix[0].size() == 3)
			}// for i

			// ���������� ������� ���������
			m_matrix = vec_1;
			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// �������� �� �������� ���������
		case('l'):
		case('L'):
		{
			cout << "\n\t\t\t\t\x1b[32m � �   � � � � � � �   � � �   � � � � � � �   -   � � � � � �   � � � � � � � � �\n\n\x1b[30m\n";

			// ������ �� ����� ���������
			string line;
			int rowNumber = 0;            // ����� ������� ������

			// ������ ����������
			while (getline(fin, line))
			{
				// ���� ������ ������, ��������� ������� ������ ������
				if (line.empty())
				{
					matrix.push_back(vector<int>(m_size, 0));
				}
				// ������ �� ������
				else
				{
					// ������ ������
					vector<int> row;
					// ������� ����� ��� ������ �������� �� ������ line. ����� �� ����� ������������ iss ������ � ���������� >> ��� ���������� �������� �� ������.
					istringstream iss(line);
					// ��������� �������� ��� ������
					int value;

					// ������ �������� �� ����� � �������� ��� � ������ ������
					while (iss >> value)
					{
						row.push_back(value);
					}// while

					// �������� ������ � �������
					matrix.push_back(row);
				}// if (line.empty()) 

				// ����������� ����� ������
				rowNumber++;
			}// while (getline(fin, line)) 

			// ���� �������� - ��������� ���
			fin.close();

			m_size = matrix.size();                         // ������ ������� ���������

			vector<vector<int>> vec_1(m_size);              // ��� ������� ��������� �������� m_size

			for (int i = 0; i < m_size; i++)                // ����� ������ ������ ������ ��� ������� ���������
			{
				// ��������� ��������������� ������� ������ �� ����� �������
				vec_1[i].resize(m_size, 0);
			}// for i

			for (int i = 0; i < m_size; i++)                 // ��������� ��� ������� ��������� 
			{
				for (int j = 0; j < matrix[i].size(); j++)
				{
					// ������� � ��� ��������, ������� ����������� ��� ������ � �����
					vec_1[i][matrix[i][j] - 1] = 1;
				}// for j
			}// for i

			// �������� �������� � �������� ������� ���������
			for (int i = 0; i < m_size; i++)
			{
				row.clear();
				for (int j = 0; j < m_size; ++j)
				{
					row.push_back(vec_1[i][j]);
				}// fot j

				m_matrix.push_back(row);
			}// for i

			// ��������� ���� �� ����. ������� ���������
			spravka = false;
			break;
		}

		// ������������ ������ �������
		case('h'):
		case('H'):
		{
			// ��������� ���� ����� ��������� ������� �� ������
			spravka = true;
			// ������� �������
			Usloviya();
			break;
		}

		// ����� - ������������ ��� �� ��� ����. ����������� ��������� � �������
		default:
			cout << "\n\x1b[31m ������������� ��������� � ������� �������� �� ������ ������!!!\n\x1b[30m";
			// ��������� ���� ����������
			fin.close();
			exit(0);
		}
	}
	// ��������� ���� ����������
	fin.close();
	// ���������� ������ ���������/ ��������������� ������� ���������
	m_size = m_matrix.size();
}

// ����������
Graph::~Graph()
{
	// ������ ���� - ������� ������������ �������������
}

// ������ ��� ��������� �������� �������
const int Graph::GetSize()
{
	// ���������� �������� ������� �������
	return(m_size);
}


// ������� ������������ True, ���� ���� ���������������, False, ���� ���� �������;
bool Graph::is_directed()
{
	// ��� �� �������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ��������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ���� �����������������, �� ������� �����������, ��� ��� �� ����� ����� ������ ������ ������������
			if (m_matrix[i][j] != m_matrix[j][i])
			{
				return true; // ������� ������������ ����� - ���� ���������������
			}// if (m_matrix[i][j] != m_matrix[j][i])

		}// for j

	}// for i

	return false; // �� ������� ������������ ����� - ���� �����������������
}


// �������, ������������ ������� ���������
vector<vector<int>> Graph::adjacency_matrix()
{
	return(m_matrix);
}


// ������� �������, ��������� ������ ������, ���������� ��� �����, ������������ ��;
int Graph::Weight(int Vi, int Vj)

{
	// ������ ������ ����� �� ��������� ���������� ��������
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		cout << "������! ����� ������� �� ����������\n";
		// ������� ������
		return(-1);
	}// if

	// ���� ���� ����������(� ������� ��������� �� 0)
	if (m_matrix[Vi][Vj] != 0)
	{
		cout << "��� ����� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		cout << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����� ����� ���������
		return(m_matrix[Vi][Vj]);
	}// if

	// ���� ���������������. ������� ��� ����
	else if ((m_matrix[Vi][Vj] != m_matrix[Vj][Vi]) && (m_matrix[Vi][Vj] != 0 || m_matrix[Vj][Vi] != 0))
	{
		cout << "���� ���������������. ���� ����. ����������� �����������. ��� ���� ����� ��������� " << Vi << " � " << Vj << " �����" << m_matrix[Vi][Vj] << endl;
		// ���������� ��� ����
		return(m_matrix[Vi][Vj]);
	}// else if

	// ����� ����� ��������� ��� - ������� ������� ��������� ����� 0
	else if (m_matrix[Vi][Vj] == 0)
	{
		cout << "����� ����� ��������� " << Vi << " � " << Vj << "���\n";
		// ������� ������� ��������
		return(m_matrix[Vi][Vj]);
	}// else if

	return(0);
}


// �������, ����������� ������ ������ � ���������� True, ���� � ����� ���� ��������������� ����� / ����, False, ���� ����� ���;
bool Graph::is_edge(int Vi, int Vj)
{
	// ������ ������ ����� �� ��������� ���������� �������� - ���� ���
	if ((Vi >= m_size || Vi < 0) || (Vj >= m_size || Vj < 0))
	{
		// �������, ��� ���� ���
		return(false);
	}// if

	// ������� ������� ��������� �� ����� 0 - ����� ����
	if (m_matrix[Vi][Vj] != 0)
	{
		// ������������, ��� ����� ����
		return(true);
	}// if

	// ������� ������� ��������� ������� - ����� ���
	if (m_matrix[Vi][Vj] == 0)
	{
		// ������������, ��� ����� ���
		return(false);
	}// if

}


// �������, ������������ ������ ������, ������� ������� v;
vector<int> Graph::adjacency_list(int v)
{
	// ������ ������
	vector<int> adjList;

	// �������� �� ���� �������� � ���������, ���� �� ����� ����� �������� v � ������� ��������
	for (int i = 0; i < m_size; i++)
	{
		// ���� ���� - ������� ������� �� �������
		if (m_matrix[v][i] != 0)
		{
			// �������� ������� � ������
			adjList.push_back(i);
		}// if (m_matrix[v][i] != 0)

	}// for i

	// ���������� ������ ������� ������
	return adjList;
}


// �������, ������������ ������ ���� ���� �����;
vector<pair<int, int>> Graph::list_of_edges_pairs()
{
	// ������ ���, ���������� ����� � ���� ���� ����������� ��� ������
	vector<pair<int, int>> edges_pairs;
	// ��� �� ���� ��������� ������
	for (int i = 0; i < m_size; i++)
	{
		// ��� �� ���� ��������� �������
		for (int j = 0; j < m_size; j++)
		{
			// ���� ������� �� �������
			if (m_matrix[i][j] != 0)
			{
				// ��������� ���� ������
				edges_pairs.push_back(make_pair(i, j));
			}// if (m_matrix[i][j] != 0)
		}// for j
	}// for i

	// ������� ������ ���� (��� ������)
	return(edges_pairs);
}


// �������, ������������ ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
vector<pair<int, int>> Graph::list_of_edges(int v)
{
	int count = 0;
	vector<pair<int, int>> edges;         // ������ ��� ������(������ ����)
	vector<pair<int, int>> edges_inc;     // ������ ���� ����������� ������� v / ��������� �� ������� v
	edges = list_of_edges_pairs();        // �������� ��� ���� ������ �����

	// ������� ��� ����. ���� ���� �����������������, �� ��� ����� ���� (v,n) � (n, v) - ���������� ����������� ��� ������������� ������ �������. � ������� - ��������� ������� ������ ������
	for (int i = 0; i < edges.size(); i++)
	{
		// ������������� ������ ������� ����
		if (edges[i].first == v)
		{
			// �������� � ����� �����, ����������� ������� ������ �����
			edges_inc.push_back(edges[i]);
			// ����������� �������
			count = count + 1;
		}//if (edges[i].first == v)
	}//for i

	// ����������  ������ ���� ���� �����, ����������� ������� v / ��������� �� ������� v
	return(edges_inc);
}




/*------------------------------------------------------------------------*/
/*                �������               */
/*--------------------------------------*/

// ���������� ����� ��� ����������
string drawGraph(const vector<vector<int>>& adjacencyMatrix)
{
	// ��������� ������ ������� ���������. ���� ������ 25, �� ������� �� ������� �������
	if (adjacencyMatrix.size() <= 19)
	{
		bool key = false;
		// ��������� ������� ����� �� ������, ����� ������, ����� �� ��������� �� ��� ������
		for (int i = 0; i < adjacencyMatrix.size(); i++)
		{
			for (int j = 0; j < adjacencyMatrix.size(); j++)
			{
				// ���� ��� ����� ������ 1 ��� �������������, ������, ����� ��������� ��� � ������
				if (adjacencyMatrix[i][j] > 1 || adjacencyMatrix[i][j] < 0)
					key = true;
			}
		}

		// ��������� ���� ��� ������ ����� � ������� DOT
		std::ofstream file;
		file.open("graph.dot");
		file << "digraph G {" << endl;

		if (key)
		{
			// ������� ���� � ��������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� �� ����� 0, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] != 0)
					{
						// ������� ����� � ��������� ���� � ������� DOT
						file << i << " -> " << j << " [label=\"" << adjacencyMatrix[i][j] << "\"];" << endl;
					}// if (adjacencyMatrix[i][j] != 0) 
				}// for j
			}// for i
		}

		else
		{
			// ������� ���� ��� �������� ����� �����
			for (int i = 0; i < adjacencyMatrix.size(); i++)
			{
				for (int j = 0; j < adjacencyMatrix[i].size(); j++)
				{
					// ���������, ��� ��� ����� ����� 1, ����� �� �������� �������� �����
					if (adjacencyMatrix[i][j] == 1)
					{
						// ������� ����� ��� �������� ���� � ������� DOT
						file << i << " -> " << j << ";" << endl;
					}//if (adjacencyMatrix[i][j] == 1) 
				}// for j
			}// for i
		}// if key

		// ��������� ���� � ��������� ����������
		file << "}" << std::endl;
		file.close();

		// ���������� ����������� ����� � ������� PNG � ������� ������� DOT
		system("dot -Tpng graph.dot -o graph.png");
		cout << "\n\nGraph image saved as graph.png" << endl;
	}

	// �������, ��� ���� ������� ��� ���������
	else
	{
		cout << "\n\nGraph image is not saved as graph.png. It is too big" << endl;
	}// if

	// ���������� �������� ��� �������� ������ OpenCV
	return "graph.png";
}


// ����� ����� �� �����
void OpenImage(const std::vector<std::vector<int>>& adjacencyMatrix)
{
	// ��������� ����������� ������� ���������
	if (adjacencyMatrix.size() <= 19)
	{
		// �������� ���� � �����������, ���������� � ������� ������� drawGraph
		std::string imagePath = drawGraph(adjacencyMatrix);
		// ��������� ����������� � ������� OpenCV
		cv::Mat img = cv::imread(imagePath, -1);

		// ���������, ������� �� ��������� �����������
		if (img.empty())
		{
			cout << "Could not open or find the image" << endl;
			return;
		}// if

		// ������� ���� � ��������� "Graph"
		cv::namedWindow("Graph", cv::WINDOW_NORMAL);
		// ���������� ����������� � ����
		cv::imshow("Graph", img);
		// ����, ���� ������������ ������ ����� �������
		cv::waitKey(0);
		// ��������� ����
		cv::destroyWindow("Graph");
		return;
	}// if (adjacencyMatrix.size() <= 19)
}


// ����� ������� ��������� �� �����
void PrintMatrix(vector<vector<int>> matrix)
{
	// ��������� ������� ����
	setlocale(0, "C");            // ������� ������ � �������� �������
	cout << setw(2) << setfill(' ') << (char)218 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)191 << endl;          // ����� ������� ���������� ������

	// ��� �� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		cout << setw(5) << setfill(' ');
		// ��� �� ��������
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ������� �������
			cout << matrix[i][j] << " ";
		}// for j

		cout << endl;
	}// for i
	cout << setw(2) << setfill(' ') << (char)192 << (char)196 << (char)196 << setw(matrix.size() * 2 + 7) << setfill(' ') << (char)196 << (char)196 << (char)217 << endl;          // ����� ������� �������
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");

	// ���������� ��������� ��������
	return;
}


// ������ ������� � ������� ������
void Usloviya()
{
	cout << "\n\t\t\t\t/*******************************************************************************\n";
	cout << "\t\t\t\t* � � � � � � � � � � � �   � � � � � �  �9  � �   5   � � � � � � �   �  +  +   *\n";
	cout << "\t\t\t\t*--------------------------------------------------------------------------------*\n";
	cout << "\t\t\t\t* Project Type  : Win64 Console Application                                      *\n";
	cout << "\t\t\t\t* Project Name  : Teor_Grph_Lab10                                                *\n";
	cout << "\t\t\t\t* File Name     : Lab10. CPP                                                     *\n";
	cout << "\t\t\t\t* Programmer(s) : ������� �.�.                                                   *\n";
	cout << "\t\t\t\t* Modifyed By   :                                                                *\n";
	cout << "\t\t\t\t* Created       : 10/10/23                                                       *\n";
	cout << "\t\t\t\t* Last Revision : 22/10/23                                                       *\n";
	cout << "\t\t\t\t**********************************************************************************/\n";

	cout << "\n\t\t\t\t\t\t\t\x1b[31m   � � � � � � � : \n\n\x1b[30m";
	// ������� ������� � �������
	setlocale(0, "C");                       // ��������� ������� ����
	cout << char(218) << setw(40) << setfill((char)196) << (char)191 << endl << (char)179;  // ������� ������� ������ �����
	setlocale(LC_ALL, "Rus");                // ���������� ������� ����
	cout << " �������� ���� ������� �� ������:      ";
	setlocale(0, "C");                       // ��������� ������� ����
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)194 << setw(35) << setfill((char)196) << (char)180 << setfill(' ') << endl << (char)179;    // ������� ������ ������ ����� � ������������ ����� ������� � ��������� ���������
	cout << "  e " << (char)179 << "  Edges_list_file_path            ";                                                                                                         // ������� ������� ������ � ������ � �������� ��������� �������
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  m " << (char)179 << "  Adjacency_matrix_file_path      ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  l " << (char)179 << "  Adjacency_list_file_path        ";
	cout << (char)179 << endl << (char)195 << setw(5) << setfill((char)196) << (char)197 << setw(35) << setfill((char)196) << (char)180 << endl << (char)179;
	cout << "  o " << (char)179 << "  Output_file_path                ";
	cout << (char)179 << endl << (char)192 << setw(5) << setfill((char)196) << (char)193 << setw(35) << setfill((char)196) << (char)217 << endl;
	cout << endl;
	setlocale(LC_ALL, "Rus");               // ���������� ������� ����

	return;                                 // ���������� ��������� ��������
}


// ������� ���������� ��������� �� ���������� ����
void updateSpecialAntPheromones_my(const vector<int>& antTours,        // ������, ���������� ������� ��������� ������� �������� 
	                               vector<vector<double>>& pheromones, // ��������� ������ � ���������� �� ������ �����
	                               vector<vector<int>>& distances)     // ��������� ������ � ������������ ����� ��������
{
	double tourLength = 0.0;                                           // ����������, �������� ����� ���� �������

	// ���� ������������ ���������� ���� ���������� �������
	// ��������� ����� ���� �������, ����������� � ������������ � antTours
	for (int i = 0; i < antTours.size() - 1; i++)
	{
		int city1 = antTours[i];
		int city2 = antTours[i + 1];
		tourLength = tourLength + distances[city1][city2];             // ����� ����� ���� 
	}// for i

	// ���� ���������� ���������, ��� ���������� ��������� ��������� �� ����������� ��������� � ���������� ��������, �������� ���������� �� ���������� ������������������ ��� ���������� ������ ������������ �����
	for (int i = 0; i < distances.size() - 1; i++)
	{
		// �������� ������ ������� ����� ����
		int city1 = antTours[i];
		// �������� ������ ������� ����� ����
		int city2 = antTours[i + 1];

		// �������� �������� �� ����� �� ����������� ���������� � ��������� ����������� ������������������, ������� �� ����������
		pheromones[city1][city2] = pheromones[city1][city2] * (1.0 - EVAPORATION_FACTOR) + SPECIAL_ANT_FACTOR / tourLength;
		pheromones[city2][city1] = pheromones[city2][city1] * (1.0 - EVAPORATION_FACTOR) + SPECIAL_ANT_FACTOR / tourLength; // ��� ��� �� ��������������� ����. ��������� ������������ �������� � �������
	}// for i

	// ������� ��������� ��������
	return;
}


// ����� ���������� ���� ��� �������
int selectNextCity(int ant,                                            // ����� �������� �������
	               int currentCity,                                    // ������� �����, � ������� ��������� �������
	               const vector<bool>& visited,                        // ������, �����������, ����� ������ ��� ��������
	               vector<vector<double>>& pheromones,                 // ��������� ������ � ������� ��������� �� ������ �����
	               vector<vector<int>> distances,                      // ��������� ������ � ������������ ����� ��������
	               vector<bool> perfect_ant)                           // ������, �����������, �������� �� ������� ������� "���������"
{
	
	double total = 0.0;                                                // ��������������� ���������� ��� ������������ �������� � ����������� ������� (��� ���������� ������)
	vector<double> probabilities(distances.size(), 0.0);               // ������, � ������� �������� ����������� �������� � �����-�� �������

	// �������� �� ���� ������� (�������� ������� ���������)
	for (int city = 0; city < distances.size(); city++)
	{
		// ���� ������� ��� �� �������� � � �� ���� ����, �� 
		if (!visited[city] && distances[currentCity][city] != 0)
		{
			double pheromone = pow(pheromones[currentCity][city], ALPHA);    // ���������� �������� �������� � �������  ALPHA
			double distance = pow(1.0 / distances[currentCity][city], BETA); // ���������� �������� �������� ���������� � ������� BETA
			probabilities[city] = pheromone * distance;                      // ���������� ���������, ��� ���������� ����������� ������� �������
			total = total + probabilities[city];                             // ������������ ����������� ( ���������� ����� �����������, ������� � ����� ������ ���� 1)
		}// if

	}// for city


	double random = static_cast<double>(rand()) / RAND_MAX;                  // ���������������� ���������� random, ������� �������� ��������� ����� �� 0 �� 1.��� ����� ������������ ������� rand(), ������� ���������� ��������� ����� �����,
	// ����� ��� ����� ������������� � ��������� �� 0 �� 1 � ������� ������� �� RAND_MAX � ���������� � ���� double.
	double cumulativeProbability = 0.0;                                      // ����������, �������� ����� �����������
	double chance = 0;                                                       // ���������� ��� �������� �����������
	int c_city = -1;                                                         // ���������� ��� �������� ��������� �������, � ������� ����� �������

	// ���� ��� - ������� �������
	if (!perfect_ant[ant])
	{
		// ������ �� ���� ��������� �����
		for (int city = 0; city < distances.size(); city++)
		{
			// ���� ������� ��� �� �������� � � �� ���� ����, �� 
			if (!visited[city] && distances[currentCity][city] != 0)
			{
				// ������������ ������������ (����������� ���������� �������� ����� ����������� ���������� � ������������. �� 100 �� �� �������� -> ��������� ����� � ��������� �� 0 �� 1
				cumulativeProbability = cumulativeProbability + probabilities[city] / total;
				// ����� ��������� ����������� ��������� ��� ���������� ������ random, ���������� ����� � ��������������� ������������. 
				// ��� ���� ���� ����������� ������ �������� � �������� ����������� � ��������� ���������.
				if (random <= cumulativeProbability)
				{
					// ���������� �����, � ������� ��� �������
					return city;
				}// if

			}// if

		}// for city

	}// if

	// ���� ��� - ��������� �������
	else if (perfect_ant[ant])
	{
		// ������ �� ���� ��������� �����
		for (int city = 0; city < distances.size(); city++)
		{
			// ����� ����� ������������ ������ 
			if (!visited[city] && distances[currentCity][city] != 0)
			{
				// ������� �������� ����� � ���������� ������������ �� ��������� ������� � ������������ ��� �����.
				if (chance < probabilities[city] / total) 
				{
					chance = probabilities[city] / total;  // ���������� �����������
					c_city = city;                         // ���������� ��������� �������
				}// if

			}// if

		}// for city

	    // ���������� �������, ����������� ������� �� ������� ���������� - ��������� ����� ��� ���������� �������
		return c_city;
	}// else if

	// ����� - ������ ������ ��� ��������� �������� ���. �� �� �������
	return -1;
}


// ������� ������ �� �����. ������ ������� ��� ������ �������
vector<int> constructTour(int ant,                                     // ����� �������
	                      vector<vector<double>>& pheromones,          // ��������� ������ �������� ��������� �� ������ �����
	                      vector<vector<int>> distances,               // ��������� ������ ���������� ����� �������� �����
	                      vector<bool> perfect_ant)                    // ������ ������� ��������, �����������, �������� �� ������� "���������"
{

	vector<bool> visited(distances.size(), false);                     // ������ ����������� ��������� �������. ������� ��� ������� �� ��������
	int currentCity;                                                   // ����������, �������� ������� �������
	int a;                                                             // ��������������� ����������, �������� �������, � ������� ������� ����� ���� ���� 

	// ����������� �������� ������, �� �������� �������� �������.
	// ���� ���-�� �������� (� ������ ������ ��������� �� ������ �������) ����� ������ ���-�� ������, �� ������� ����� ������ ��������� �� ��������� �����
	if (ant > distances.size() - 1)
	{
		// ���� ����� ������� (ant) ��������� ���������� �������, �� ������� ����� ��������������� ��� ant �� ������ ���������� �������
		currentCity = ant % distances.size();                          // ���� ������� �� ������� ������ ������� �� ������ ������� ���������
		a = currentCity;
	}

	// ����� ������� ����� ����� ant
	else
	{
		currentCity = ant;
		a = currentCity;
	}// if

	// ������� �������� ������ ��� ����������� � ���������� ��� � �������
	visited[currentCity] = true;                                      // ��������� ������� �������� ���������� (� ��� ��������� �������)
	vector<int> tour;                                                 // ������ ������, � ������� ����� ��������� ������� ����� ������� �� ��������
	tour.push_back(currentCity);                                      // ����� ��������� ������� � ������ ������

	// ���� ���������� ������ � ������� �� ����� ����� ���������� ������ � ����� (� ������ ������������ ��� ������� ������ ���� ��������) 
	while (tour.size() < distances.size())
	{
		// ������� �������, � ������� ����� ���� �������� �������
		int nextCity = selectNextCity(ant, currentCity, visited, pheromones, distances, perfect_ant);

		// ���� ������ ��������� ����� (nextCity) � �� ��� �� ��� �������, �� ����������� � �������, ���������� ��� ����������, �
		// ������� ����� ����������� �� �����
		if (nextCity != -1)
		{
			tour.push_back(nextCity);                                // ����� ����� ������� � ������
			visited[nextCity] = true;                                // �������� � ��� ����������
			currentCity = nextCity;                                  // ��������� ������� ����� �� �����
		}// if

	}// while

	// �������� ������� ���� �� �������� ������ ������� � ��������� ������, � �������� ������� �����.
	// ���� ����� ����������, �������� ����� ����������� � �������.
	if (distances[currentCity][a] != 0)
	{
		tour.push_back(a);
	}// if

	// ���������� ������������ ����� �� ���� ���������� �������
	updateSpecialAntPheromones_my(tour, pheromones, distances);

	// ������� ����������� ������� � ���� ������� ����� �����
	return tour;
}


// ������� ���������� ���������� �����
vector<vector<int>> constructAntTours(vector<vector<double>>& pheromones, // ��������� ������ �������� ��������� �� ������ �����
	                                  vector<vector<int>> distances,      // ��������� ������ ���������� ����� �������� �����
	                                  vector<bool> perfect_ant)           // ������ ������� ��������, �����������, �������� �� ������� "���������" 
{
	vector<vector<int>> antTours;                                         // �������, �������� ���������� ����

	// � ����� �� ������� �������, �� 0 �� NUM_ANTS, ���������� ������� constructTour ��� �������� ����������� ���� ��� �������� �������
	for (int ant = 0; ant < NUM_ANTS; ant++)                                        // ���� �� ��������
	{
		vector<int> tour = constructTour(ant, pheromones, distances, perfect_ant);  // ���������� ���� ����� ��������
		antTours.push_back(tour);                                                   // ������������ ����� ���� � ������� �����
	}// for ant

	// ������������ ������� antTours, ���������� ��� ����������� ���������� ����
	return antTours;
}


// ������� ������ ������� (������������) ���� ����� ���� ��������
vector<int> findBestTour(const vector<vector<int>>& antTours,             // ��������� ������ ���������� �����
	                     vector<vector<int>> distances)                   // ��������� ������ ���������� ����� ��������
{
	vector<int> bestTour;                                                 // ������, �������� ������ ����
	double bestlen = INF;                                                 // ����������, �������� ����� ������������ ������� ����
	double len = 0;                                                       // �������� ����� ���� ���� �������

	// � ����� �� ������� ����������� ���� � antTours
	for (int i = 0; i < antTours.size(); i++)
	{
		// �������� �� ������� ������ � ����, ������� �� ������� ������
		for (int j = 1; j < antTours[i].size(); j++)
		{
			// c�������� ���� ����� ����� ������� ������� � ���������� �������
			len = len + distances[antTours[i][j - 1]][antTours[i][j]];
		}// for j

		// ���������� ������������ ���� ����� ���� ���������� �����
		// ���� �������� len ������ �������� �������� bestlen, �� ��������� bestlen � ��������� ������� ���� � bestTour
		if (bestlen > len)
		{
			bestlen = len;
			bestTour = antTours[i];
		}// if

		// �������� ���������� len ��� ������������ ������� ���� ���������� ����
		len = 0; // ��������� �������� ����

	}// for i

	// ���������� ������ bestTour, ���������� ������ ���� ����� ���� ���������� �����
	return bestTour;
}


// �������, ������� ��������� ��������� ��������� ����� ������� ���� ��������
void evaporatePheromones(vector<vector<double>>& pheromones,              // ��������� ������, �������������� ������� ��������� ����� ��������
	                     vector<vector<int>>& distances)                  // ��������� ������, �������������� ������� ���������� ����� ��������
{
	// �� ������� ����� ������������ ��� ������ ������� ��������� pheromones
	for (int i = 0; i < distances.size(); i++)
	{
		// �� ���������� ����� ������������ ��� ������� ������� ��������� pheromones
		for (int j = 0; j < distances.size(); j++)
		{
			// ��������� �������� �� ���� ���������
			pheromones[i][j] = pheromones[i][j] * (1.0 - EVAPORATION_FACTOR);
		}// for j

	}// for i
}


// ����� �������  � ����
void PrintMatrToFile(vector<vector<int>> matrix)                 // �������, ������� ���������� ������� � ����. �������� �� ��������
{
	// ��� �� ������� �������
	for (int i = 0; i < matrix.size(); i++)
	{
		// ��� �� �������� �������
		fout << " ";
		for (int j = 0; j < matrix.size(); j++)
		{
			// ������� ��������� ������� ������� � ����
			fout << matrix[i][j] << " ";
		}// for j
		fout << endl;
	}// for i

	// ���������� ��������� ��������
	return;
}




/*------------------------------------------------------------------------*/
/*            ������� �������           */
/*--------------------------------------*/
int main()
{
	// ���������� ������� ����
	setlocale(LC_ALL, "Russian");
	// ���� ������� - �����
	system("color F0");
	// ���� ������ � ����. ���������� - ������ ���
	bool print = false;
	// ����, �������� ������������� ��� ������
	char letter;

	cout << "\t\t\t\t\t\t\x1b[34m    � � � � � �   �   � � � � � � �\x1b[30m\n\n\n";
	// ������� ������ �����. ����������� ���������� ��-���������
	Graph NewGraph;

	// �����, ����� �� ������������ �������� � ���� ����������� ����������
	cout << " ������ �� �� �������� ������ � ����? ������� <o>, ���� ������, ��� ����� ������ ������ - ���� ���. �������: ";
	cin >> letter;                             // ���� �������������
	cout << "\n �� �����: " << letter;         // ���-������

	// ���� ������������ ����� ��������. ������������� ����
	if (letter == 'o' || letter == 'O')
	{
		print = true;

	}// if (letter == 'o' || letter == 'O')


	// ������� ������� ��������� �� ������ �� ����� �� �����
	cout << "\n\n\t\t\t\t\x1b[35m    � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\x1b[30m\n\n";
	PrintMatrix(NewGraph.adjacency_matrix());

	vector<vector<double>> pheromones(NewGraph.GetSize());        // ������� ���������, ������� ��������� �� ������ �����
	vector<vector<int>> m_matrix = NewGraph.adjacency_matrix();   // ������� ��������� ����� - ������� ������� � ���������� ����� ����
	
	// ��������� ������� ��������� ���������� 0
	for (int i = 0; i < pheromones.size(); i++)
    {
        pheromones[i].resize(m_matrix.size(), 0);
    }// for i

	// ������������� ���������
	// ��� �� ���� ������� ������� ���������
	for (int i = 0; i < m_matrix.size(); i++)
	{
		// ��� �� ���� �������� ������� ���������
		for (int j = 0; j < m_matrix.size(); j++)
		{
			// ���� �������� m_matrix[i][j] �� ����� 0, ��������������� �������� INITIAL_PHEROMONE � ��������������� ������ ������� pheromones
			if (m_matrix[i][j] != 0)
			{
				// �������� ������������ ���� ���������� ���������� ��������
				pheromones[i][j] = INITIAL_PHEROMONE;
			}// if

		}// for j

	}// for i

	// ������, ������� ���������� ��������� �������� 
	vector<bool> perfect_ant(NUM_ANTS, false);

	// ����� ������ NUM_SPECIAL_ANTS ��������  - �� ���������, ��������� - ��������� 
	for (int i = NUM_SPECIAL_ANTS; i < NUM_ANTS; i++)
	{
		perfect_ant[i] = true;
	}// for i


	vector<vector<int>> antTours;     // ������� ����� ��������
	vector<int> bestTour;             // ������, �������� ������ ����
	vector<int> min_tour;             // ������, �������� ��� ������������ ����
	int min = INF;                    // ����������, �������� min
	int sum = 0;                      // ������������� ���������� �������� ����� ���� � ����

	// ���� �� ���������� ���������� 
	for (int i = 0; i < MAX_ITERATIONS; i++)
	{
		antTours = constructAntTours(pheromones, m_matrix, perfect_ant);   // ��������� ����� ���������� ��������
	    bestTour = findBestTour(antTours, m_matrix);                       // ���������� ������� ����

		// ���������� ���������� ������� ���� �� ������ ����������
		for (int j = 1; j < bestTour.size(); j++)
		{
			// ��������� ���� ���� ����, �������� � ������ ����
			sum = sum + m_matrix[bestTour[j]][bestTour[j - 1]];
		}// for j

		// ����� ������������ ���� ����� ���� ���������� ���������� ��������
		if (min > sum)
		{
			min = sum;
			min_tour = bestTour;
		}// if

		// ���������� ������� evaporatePheromones, ������� ��������� ������� ��������� ��������� �� ������ ����� �����, ��������� ������� pheromones � m_matrix
		evaporatePheromones(pheromones, m_matrix);

		// ��������� �������� �����
	    sum = 0;                // ��������� �����
		antTours.clear();       // ������� ������� ����� ��������
		bestTour.clear();       // ������� ������� � ������ ���������� ����� �� ������ ����������

	}// for i

	cout << "\n\t\t\t\t\t\x1b[31m       � � � � � � � �   � � � � � � � � � �   � � � � � � � :\x1b[30m\n\n";

	// ����� ���� ������� ����������� ����
	cout << "\x1b[36m ����������� ���� ����� ����� \x1b[30m" << min << endl << endl;

	// ����� ������� ����������� ����
	// ��� �� ��������� ������� ����
	for (int i = 0; i < min_tour.size()-1; i++)
	{
		// ������� ������� � ������� ����������
		cout << " " << min_tour[i] + 1 << " - " << min_tour[i + 1] + 1 << " : " << NewGraph.adjacency_matrix()[min_tour[i]][min_tour[i + 1]];
		cout << endl;
	}// for i

	// ����� � ����
	if (print)
	{
		fout.open(FNAMEOUT);           // ��������� ������ � ������
		if (!fout.is_open())           // ���� �� ������
		{
			cout << "����� � ����� ������ ���. ���������� ����������� ������";
			fin.close();               // ������� ���� ��� ������
			system("pause");
			exit(0);                   // ���������� ��������, ��������������� ���� � caller
		}// if (!fout.is_open())

		fout << "\t\t\t\t\t\t    � � � � � �   �   � � � � � � �";
		fout << "\n\n � � � � � � �   � � � � � � � � �   � �   � � � � � � � �   � � � � � � :\n\n";
		// ������� ������� ��������� � ����
		PrintMatrToFile(NewGraph.adjacency_matrix());

		fout << "\n � � � � � � � �   � � � � � � � � � �   � � � � � � � :\n\n";

		// ����� ���� ������� ����������� ����
		fout << " ����������� ���� ����� ����� " << min << endl << endl;

		// ����� ������� ����������� ����
		// ��� �� ��������� ������� ����
		for (int i = 0; i < min_tour.size() - 1; i++)
		{
			// ������� ������� � ������� ����������
			fout << " " << min_tour[i] + 1 << " - " << min_tour[i + 1] + 1 << " : " << NewGraph.adjacency_matrix()[min_tour[i]][min_tour[i + 1]];
			fout << endl;
		}// for i
	}// if

	// ������� �������� � ������ �� �����
	OpenImage(NewGraph.adjacency_matrix());
	// ��������� ���� ��� ������
	fin.close();
	// ���������� ��������� �������� � �������
	return 0;
}