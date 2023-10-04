#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
using namespace std;

// Make a function that creates the [filename]_set.txt file 
void createSetFile(string filename, set<string> unique){   
    ofstream setfile(filename + "_set.txt");

    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
        // cout << ' ' << *it;
        setfile << ' ' << *it;
    }
    setfile.close();
}

// Make a function that creates the [filename]_vector.txt file
void createVectorFile(string filename, vector<string> tokens){
    ofstream vectorfile(filename + "_vector.txt");
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
        vectorfile <<  *it << endl;
    }
    vectorfile.close();
}
// Make a function that makes a map of each word to the word that comes next in the vector
// For example, for the string vector “having been born of goodly parents”, you would add the entries (key=”having”, value=”been”), (key=”been”, value=”born”), (key=”born”, value=”of”), etc.
void makeMapFile(vector<string> tokens,string filename){
    map<string, string> wordmap;
    string last="";
        for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap[last]=*it;
        last = *it;
    }
    // Print out the map to a file named the file [filename]_map.txt. 
    // On each line of the file, output the key a comma and space “, “, and then the value.
    ofstream mapfile(filename + "_map.txt");
    
    for (auto it = wordmap.begin(); it != wordmap.end(); it++) {
        mapfile << it->first << ", " << it->second << endl;
    }
    mapfile.close();
}

int main(int argc, char *argv[]) {

    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string filename = argv[1];
    ifstream in(filename);

    // //split filename by . and get the first part
    // string delimiter = ".";
    // filename = filename.substr(0, filename.find(delimiter)); 
    // cout << filename << endl;

    // Read each line of the file
    while (getline(in, next_line)) {
        istringstream iss(next_line);
        string token;
        while (iss >> token) {
            string nopunct = "";
            for(auto &c : token) { // Remove Punctuation      
                if (isalpha(c)) {
                    nopunct +=c;       
                }
            }
	          tokens.push_back(nopunct);
		        unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    cout << "Number of words "<<tokens.size()<<endl;
    cout << "Number of unique words "<<unique.size()<<endl;

    // create set file
    createSetFile(filename, unique);
    
    // create vector file
    createVectorFile(filename, tokens);

    // create map file
    makeMapFile(tokens, filename);


    return 0;
}



// part 3?
// map<string, string> wordmap;
//     for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
//         // cout << ' ' << *it;
//         wordmap[*it]++;
//     }
//     for (map<string, int>::iterator it=wordmap.begin(); it!=wordmap.end(); ++it){
//         // cout << ' ' << *it;
//         vectorfile << ' ' << *it;
//     }
//     vectorfile.close();