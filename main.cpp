#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include "headers/ff.h"
#include "headers/pff.h"
#include "headers/cFunctions.h"
#include "headers/hpacket.h"
#include "headers/keyless.h"
#include <chrono>
#include <fstream>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/graph/adjacency_list.hpp>
#include <boost/property_map/property_map.hpp>
#include <nlohmann/json.hpp>

std::vector<uint8_t> generateRandomVector(int size, int _fieldsize)

{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::vector<uint8_t> randomVector(size);

  if (_fieldsize == 256)
  {
    std::uniform_int_distribution<uint8_t> dis(1, _fieldsize - 1);
    for (int i = 0; i < size; ++i)
    {
      randomVector[i] = dis(gen);
    }
  }
  else
  {

    std::uniform_int_distribution<uint8_t> dis(1, _fieldsize - 1);
    for (int i = 0; i < size; ++i)
    {
      randomVector[i] = dis(gen);
    };
  };

  return randomVector;
};

// Initialize random number generator
std::random_device rd;
std::mt19937 generator(std::random_device{}());
int main()
{
  // int argc, char *argv[]

  int m = 3;
  int n = 10;
  int f = 256;
  std::string node_type = "Source";

  //  _input_generation = g;
  //  _input_fieldSize = f;
  //  _input_symbolSize = s;

  int opt;

  // Display the number of command-line arguments
  // std::cout << "Number of arguments: " << argc << std::endl;

  // // Updated getopt string to include 'm', 'n', and 'f'
  //   while ((opt = getopt(argc, argv, "m:n:f:")) != -1) {
  //       switch (opt) {
  //           case 'm':
  //               m = std::stoi(optarg);
  //               std::cout << "Parsed m: " << m << std::endl;  // Debug message
  //               break;
  //           case 'n':
  //               n = std::stoi(optarg);
  //               std::cout << "Parsed n: " << n << std::endl;  // Debug message
  //               break;
  //           case 'f':
  //               f = std::stoi(optarg);
  //               std::cout << "Parsed f: " << f << std::endl;  // Debug message
  //               break;
  //           default:
  //               std::cerr << "Usage: " << argv[0] << " -m <generation> -n <symbolSize> -f <fieldSize> " << std::endl;
  //               return 1;  // Exit with error
  //       }
  //   }

  // Output the parsed values
  std::cout << "_input_generation: " << m << std::endl;
  std::cout << "_input_symbolSize: " << n << std::endl;
  std::cout << "_input_fiieldSize: " << f << std::endl;
  
  // set the main simulation parameters
  int _GG = 100;                      // number of generations
  int _G = 20;                        // generation size (m)
  int _fieldSize = f;                 // finite field size (f)
  int _symbolSize = n;                // (n)
  int _packetSize = _symbolSize + _G; // m+n

  // int _G = 64; // generationsize
  //  int min_G = 8;
  // int max_G = 128;
  double min_att_rate = 0;
  double max_att_rate = 0.05;
  // for (double attackProbability = min_att_rate; attackProbability < max_att_rate; attackProbability)
  //{
  //   for (int _G = min_G; _G < (max_G + 1); _G)
  //{
  // int _bufferSize = _G;
  // g[v4].path_index_vector = std::vector<int>(_bufferSize, 0);
  // g[v4].arVectorForPackets = std::vector<int>(_bufferSize, 0);
  //  simulation(g, path_list, _GG, _G, _fieldSize, _symbolSize, _packetSize, _keypoolSize, _keysetSize, number_of_fake_packets, _bufferSize, attackProbability);
  std::vector<int> _symbolSizeVector= {100,300,500,700,900};
  keyless_simulation(_G, _symbolSizeVector, _fieldSize, _GG); //
                                                        // _G += _G;
                                                        //}
                                                        // attackProbability += 0.2;
  //}
}
void keyless_simulation(int genSize, std::vector<int> _symbolSizeVector, int _fieldSize, int it)
{

  // /////////////////--------------- KEYLESS VERIFICATION ------------------------------------------------------------------//////////  //  ORIGINAL //
  // std::string filename_keyless_verification = "./Results/GenerationSize" + std::to_string(genSize) + "_";
  // filename_keyless_verification += "SymbolSize:" + std::to_string(_symbolSize) + "_";
  // filename_keyless_verification += "Field Size" + std::to_string(_fieldSize) + "_";
  // filename_keyless_verification += ".txt";
  // std::ofstream outputFile_keyless_verification(filename_keyless_verification, std::ios::app);
  // //// ------------------------------------------------------------------------------------------------------------------------------////    //  ORIGINAL //
  // std::string filename_keyless_verification_all_data = "./Results/GenerationSize" + std::to_string(genSize) + "_";
  // filename_keyless_verification_all_data += "Symbol Size:" + std::to_string(+_symbolSize) + "_";
  // filename_keyless_verification_all_data += "Field Size" + std::to_string(_fieldSize) + "_";
  // filename_keyless_verification_all_data += "all_data";
  // filename_keyless_verification_all_data += ".txt";
  // std::ofstream outputFile_keyless_verification_all_data(filename_keyless_verification_all_data, std::ios::app);
  /////////////////--------------- KEYLESS VERIFICATION ------------------------------------------------------------------//////////
  std::random_device rd;
  std::mt19937 gen(rd());

  ///////////////////// --------------------------  KEYLESS VERIFICATION TEST CENTER --------------------------------------/////////////////////////
  //    int genSize=50;
  //    int _symbolSize=5;
  int iteration_num = it;
  
  for (int x = 6; x <  9; x += 2)
  {
      /////////////////--------------- KEYLESS VERIFICATION ------------------------------------------------------------------//////////  //  ORIGINAL //
      ////////////////----------------- Security -----------------------------------------------//
  std::string filename_keyless_verification_security = "./Results/GenerationSize" + std::to_string(genSize) + "_";
  filename_keyless_verification_security += "Security -";
  filename_keyless_verification_security += "ADV:" + std::to_string(x) + "_";
  filename_keyless_verification_security += "Field Size" + std::to_string(_fieldSize) + "_";
  filename_keyless_verification_security += ".txt";
  std::ofstream outputFile_keyless_verification_security(filename_keyless_verification_security, std::ios::app);
  //// ------------------------------------------------------------------------------------------------------------------------------////    //  ORIGINAL //
  ////////////////----------------- Security All Data -----------------------------------------------//
  std::string filename_keyless_verification_security_all_data = "./Results/GenerationSize" + std::to_string(genSize) + "_";
  filename_keyless_verification_security_all_data += "Security -";
  filename_keyless_verification_security_all_data += "ADV:" + std::to_string(x) + "_";
  filename_keyless_verification_security_all_data += "Field Size" + std::to_string(_fieldSize) + "_";
  filename_keyless_verification_security_all_data += "all_data";
  filename_keyless_verification_security_all_data += ".txt";
  std::ofstream outputFile_keyless_verification_security_all_data(filename_keyless_verification_security_all_data, std::ios::app);
  ////////////////----------------- Time Consumption -----------------------------------------------//
  std::string filename_keyless_verification_time_avg = "./Results/GenerationSize" + std::to_string(genSize) + "_";
  filename_keyless_verification_time_avg += "Time Consumption -";
  filename_keyless_verification_time_avg += "ADV:" + std::to_string(x) + "_";
  filename_keyless_verification_time_avg += "Field Size" + std::to_string(_fieldSize) + "_";
  filename_keyless_verification_time_avg += ".txt";
  std::ofstream outputFile_keyless_verification_time_avg(filename_keyless_verification_time_avg, std::ios::app);
  //// ------------------------------------------------------------------------------------------------------------------------------////    //  ORIGINAL //
  ////////////////----------------- TIme Consmption All Data -----------------------------------------------//
  std::string filename_keyless_verification_time_all_data = "./Results/GenerationSize" + std::to_string(genSize) + "_";
  filename_keyless_verification_time_all_data += "Time Consumption -";
  filename_keyless_verification_time_all_data += "ADV:" + std::to_string(x) + "_";
  filename_keyless_verification_time_all_data += "Field Size" + std::to_string(_fieldSize) + "_";
  filename_keyless_verification_time_all_data += "all_data";
  filename_keyless_verification_time_all_data += ".txt";
  std::ofstream outputFile_keyless_verification_time_all_data(filename_keyless_verification_time_all_data, std::ios::app);



  for(int symInd=0; symInd<_symbolSizeVector.size(); symInd++){
    int _symbolSize= _symbolSizeVector[symInd];
    for (int y = 6; y < 9; y += 2)
    {
    //  std::cout << "(x , y) =" << (x,y) << std::endl;
      int check_counter = 0; int half_sum_check_counter=0; int multiple_sum_check_counter=0;
      int erroneous_pollution=0;

      std::srand(std::chrono::high_resolution_clock::now().time_since_epoch().count());
      std::vector<std::chrono::microseconds> duration_values_tag_gen;
      std::vector<std::chrono::microseconds> duration_values_tag_ver_individual;
      std::vector<std::chrono::microseconds> duration_values_tag_ver_half_sum;

      for (int iter = 0; iter < iteration_num; iter++)
      {
        std::vector<std::vector<uint8_t>> ReceivedPackets(genSize, std::vector<uint8_t>(genSize + _symbolSize, 0));
    do{
        for (int j = 0; j < genSize; j++)
        {
          ReceivedPackets[j] = generateRandomVector(genSize + _symbolSize, _fieldSize); // with size
        };}while(rankComputer(ReceivedPackets,genSize,_symbolSize) != genSize);

     //   std::cout<< "Rank:"<< rankComputer(ReceivedPackets,genSize,_symbolSize)<< std::endl;
        keylessPacket p2(ReceivedPackets, genSize, _symbolSize, _fieldSize);

        std::vector<std::vector<uint8_t>> tagged_received_packets(genSize, std::vector<uint8_t>(3 * genSize + _symbolSize, 0));

        for (int i = 0; i < genSize; i++)
        {
          //  tagged_received_packets[i] = p2.packetAppenderONEPACKE(transmitted_packets[i],std::vector<uint8_t>(2*_G,0));
          tagged_received_packets[i] = p2.packetAppenderONEPACKE(ReceivedPackets[i], std::vector<uint8_t>(2 * genSize, 0));
        };
        auto start_tag_gen = std::chrono::high_resolution_clock::now();
        std::vector<std::vector<uint8_t>> keyless_encoded_packets = p2.macCalculator(tagged_received_packets, genSize, _symbolSize, _fieldSize);           
        auto end_tag_gen = std::chrono::high_resolution_clock::now();
        auto duration_tag_gen = std::chrono::duration_cast<std::chrono::microseconds>(end_tag_gen - start_tag_gen);
        duration_values_tag_gen.push_back(duration_tag_gen);

        

        std::vector<std::vector<uint8_t>> polluter_packets(x, std::vector<uint8_t>(3 * genSize + _symbolSize, 0));
        std::vector<std::vector<uint8_t>> verifier_packets(y, std::vector<uint8_t>(3 * genSize + _symbolSize, 0));
        std::vector<int> polluter_vector_indices = chosenNumbers(x, genSize);
        std::vector<int> verifier_vector_indices = chosenNumbers(y, genSize);
        //  std::vector<int>polluter_vector_indices = {1, 2, 3, 4, 5};
        //  std::v...
