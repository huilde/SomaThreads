#include <chrono>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "matrix.hpp"

using std::cout;
using std::ifstream;
using std::ofstream;
using std::pair;
using std::string;
using std::stringstream;
using std::vector;
using std::chrono::duration_cast;
using std::chrono::nanoseconds;
using std::chrono::steady_clock;

bool CanMultiply(const vector<vector<int>> &fst_matrix,
                 const vector<vector<int>> &snd_matrix) {
  return false;
}

void Multiply(const vector<vector<int>> &fst_matrix,
              const vector<vector<int>> &snd_matrix) {
  vector<vector<int>> result;

}

pair<int, int> GetMatrixDimensions(const string filename) {
  pair<int, int> dimensions(0, 0);
  ifstream file(filename);
  string line;

  if (!getline(file, line)) return pair<int, int>(0, 0);
  dimensions.first++;

  stringstream ss(line);
  string cell;

  while (ss >> cell) dimensions.second++;
  while (getline(file, line)) dimensions.first++;

  return dimensions;
}

int main(int argc, char **argv) {
  auto fst_dimensions = GetMatrixDimensions(argv[1]);
  auto snd_dimensions = GetMatrixDimensions(argv[2]);

  Matrix m1 = Matrix(fst_dimensions.first, fst_dimensions.second);
  Matrix m2 = Matrix(snd_dimensions.first, snd_dimensions.second);

  ifstream file1(argv[1]);
  ifstream file2(argv[2]);
  ofstream file3("matrix3.txt");

  file1 >> m1;
  file2 >> m2;

  auto start = steady_clock::now();
  auto m3 = m1 * m2;
  auto end = steady_clock::now();
  auto duration = duration_cast<nanoseconds>(end - start).count();

  file3 << m3 << "\n";
  file3 << duration << " ns\n";
}
