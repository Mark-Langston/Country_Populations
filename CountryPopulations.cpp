#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {

    // Open the input file
    ifstream input_file("worldpop.txt");

    // Check if the file is opened successfully
    if (!input_file.is_open()) {
        cerr << "Error opening file, program terminating!" << endl;
        return 1;
    }

    // Print table header
    cout << left << setw(25) << "Country" << "Population" << endl;
    cout << "------------------------------------" << endl;

    // Variables to store each line, total population, country name, and population
    string line;
    long long total_population = 0;

    // Read each line from the file
    while (getline(input_file, line)) {
        // Use stringstream to extract country name and population from the line
        istringstream iss(line);
        string country;
        long long population;

        iss >> country >> population;

        // Exclude the entry for "European Union" from the table and calculate total population
        if (country != "European" && country != "Union") {
            // Print country name and population with even spacing
            cout << left << setw(25) << country << population << endl;
            total_population += population;
        }
    }

    // Close the input file
    input_file.close();

    // Print the total population
    cout << "------------------------------------" << endl;
    cout << "Total Population: " << total_population << endl;

    return 0;
}