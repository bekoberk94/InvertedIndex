# InvertedIndex
This application is used to create InvertedIndex Table. It takes two parameters from the user. One parameter is given as a library path, then the application creates inverted index table. Also user can search the words in the specified library.
# How to Use
In the bin folder, there are 2 subfolders called as Debug and Release. You can choose one of them and start the application from terminal like "Library.exe cli –index “path_to_library”" or "Library.exe cli –search “some_word”".
# How to Compile
In the build folder, you can find CMake file for this project. Cmake version should be 3.10.
# My Design Approach
I created two classes. One of them is gets the file from specified library. The function searchs throught the path recursively , and records the this class with required informations.
Other class is tracking the files in this class and saves the word to the map with folder information and frequency. When the user searched the word, this class find from map and print informations. I used Singleton approach to get files and words to make sure one library is created.
