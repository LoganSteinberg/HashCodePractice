#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include <type_traits>
#include <map>
#include <queue>
#include <ctime>

class CSVReader
{
	std::string fileName;
    char delimiter;

    public:
        CSVReader(std::string filename, char delimiter=',') :
                fileName(filename),
                delimiter(delimiter)
        { }

        std::vector<std::vector<int>> get();
        void set(std::string & fileName);
};

void CSVReader::set(std::string & fileName){
    this->fileName = fileName;
}

std::vector<std::vector<int>> CSVReader::get()
{
    std::vector<std::vector<int>> dataList;
	std::cout << fileName <<std::endl;
    std::ifstream file(fileName);
    if (file) {
        std::cout << "read file" <<std::endl;
    }
	std::string line;

	while(std::getline(file,line))
    {
        std::cout << "csvreader::get::whileGetLine" << std::endl;
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<int> parsedRow;
        while(std::getline(lineStream,cell, this->delimiter))
        {
            parsedRow.emplace_back(std::stoi(cell));
        }

        dataList.emplace_back(parsedRow);
    }
	// Close the File
	file.close();

    return dataList;
}

class neighbour{

    int index1;
    int index2;
    int spcost;

    public:
        neighbour(int i, int j, int cost){
            index1 = i;
            spcost = cost;
            index2 = j;
        }

        neighbour() = default;

        int getCost() const {
            return this->spcost;
        }

        int getIndex1(){
            return this->index1;
        }

        int getIndex2(){
            return this->index2;
        }
};

class compareNeighbours{
    public:
        int operator() (const neighbour& p1, const neighbour& p2)
        {
            return p1.getCost() > p2.getCost();
        }
};

class tabu_search{

    CSVReader flowRead = CSVReader("/home/batman/Documents/google_code_jam/ieeextreme_prep/Flow.csv");
    CSVReader distanceRead = CSVReader("/home/batman/Documents/google_code_jam/ieeextreme_prep/Distance.csv");

    std::vector<std::vector<int>> flowMatrix;
    std::vector<std::vector<int>> DistanceMatrix;

    int tabu_list_size;
    std::vector<int> state = std::vector<int>(20, 0);

    std::map<std::vector<int>, int> recency_frequency_matrix;
    std::map<std::vector<int>, int> frequency_matrix;

    int best_score;
    int current_state_score;
    int numIter;

    int find_cost();
    int find_cost(const std::vector<int> &);
    void swap(std::vector<int> & state, const int & index1, const int & index2);
    bool try_add(const std::vector<int> &);
    void print_recency_matrix();

    public:
        tabu_search(const int & tabu_list);
        void move();
        void solve();
        void print_matrix(const std::vector<std::vector<int>> & matrix);
        void print_matrix(const std::vector<int> & matrix);

        void test_cases();
};
