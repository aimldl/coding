// int_array_1d2bin_file-bin_file2int_array_1d-simple.cc

#include "pch.h"  // Comment out this in Linux. This is for Microsoft Visual Studio

// References
//   Save and read double array in a binary file : ofstream « File Stream « C++ Tutorial
//   http://www.java2s.com/Tutorial/Cpp/0240__File-Stream/Saveandreaddoublearrayinabinaryfile.htm

#include <iostream>
#include <fstream>

int main() {
  std::string file_name = "foobar.bin";
  std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
  std::cout << std::endl;

  //====================================================================================
  // Save an int type array to the output file.
  const int array_size = 5;
  int array_1d_output[array_size] = {1, 2, 3, 4, 5};
  for (int i = 0; i < array_size; i++)
    std::cout << " array_1d_output[" << i << "] = "<< array_1d_output[i] << std::endl;

  // Open a binary file
  std::ofstream ofs(file_name, std::ios::binary | std::ios::out);
  
  // Write to the binary file
  ofs.write((char*)&array_1d_output, sizeof(array_1d_output));
  std::cout << "Saved int array_1d_output to a binary file." << std::endl;

  // The following may be fine, but less efficient.
  //for (int i = 0; i < array_size; i++) {
  //  ofs.write((char*)&array_1d_output[i], sizeof(int));
  //}

  // Check the output file size
  ofs.seekp(0, std::ios::end);
  int output_file_size = ofs.tellp();
  std::cout << "output_file_size = " << output_file_size << std::endl;

  // Close ofstream.
  ofs.close();
  std::cout << std::endl;

  //====================================================================================
  // Open the binary file
  std::ifstream ifs(file_name, std::ios::binary | std::ios::in);
  if (ifs.fail()) {
    std::cerr << "File not found" << std::endl;
    return 1;
  }

  // Read the binary file
  int array_1d_input[array_size];
  ifs.read(reinterpret_cast<char*>(&array_1d_input), sizeof(array_1d_input)); // reinterpret_cast<char*>( &variable_name )

  // Check the input file size
  ifs.seekg(0, std::ios::end);
  int input_file_size = ifs.tellg();
  std::cout << "input_file_size = " << input_file_size << std::endl;

  ifs.seekg(0, ifs.beg);  // Don't forget to bring it back to the very beginning

  for (int i = 0; i < array_size; i++)
    std::cout << " array_1d_input[" << i << "] = " << array_1d_input[i] << std::endl;
  std::cout << "Retrieved the int array from the binary file successfully." << std::endl;

  // Close ifstream.
  ifs.close();

  return 0;
}

// Expected output
//sizeof(int) = 4
//
//array_1d_output[0] = 1
//array_1d_output[1] = 2
//array_1d_output[2] = 3
//array_1d_output[3] = 4
//array_1d_output[4] = 5
//Saved int array_1d_output to a binary file.
//output_file_size = 20
//
//input_file_size = 20
//array_1d_input[0] = 1
//array_1d_input[1] = 2
//array_1d_input[2] = 3
//array_1d_input[3] = 4
//array_1d_input[4] = 5
//Retrieved the int array from the binary file successfully.
