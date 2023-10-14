#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>
#include <list>
#include <iterator>
#include <stdlib.h>     
#include <time.h> 


using namespace std;

// // Make a function that creates the [filename]_set.txt file 
// void createSetFile(string filename, set<string> unique){   
//     ofstream setfile(filename + "_set.txt");

//     for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
//         // cout << ' ' << *it;
//         setfile << ' ' << *it;
//     }
//     setfile.close();
// }

// // Make a function that creates the [filename]_vector.txt file
// void createVectorFile(string filename, vector<string> tokens){
//     ofstream vectorfile(filename + "_vector.txt");
//     for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
//         vectorfile <<  *it << endl;
//     }
//     vectorfile.close();
// }
// // Make a function that makes a map of each word to the word that comes next in the vector
// // For example, for the string vector “having been born of goodly parents”, you would add the entries (key=”having”, value=”been”), (key=”been”, value=”born”), (key=”born”, value=”of”), etc.
// void makeMapFile(vector<string> tokens,string filename){
    // map<string, string> wordmap;
    // string last="";
    //     for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
    //     wordmap[last]=*it;
    //     last = *it;
    // }
    // // Print out the map to a file named the file [filename]_map.txt. 
    // // On each line of the file, output the key a comma and space “, “, and then the value.
    // ofstream mapfile(filename + "_map.txt");
    
    // for (auto it = wordmap.begin(); it != wordmap.end(); it++) {
    //     mapfile << it->first << ", " << it->second << endl;
    // }
    // mapfile.close();
// }


int main(int argc, char *argv[]) {

    vector<string> tokens;
    set <string> unique;
    string next_line;  // Each data line
    string filename = argv[1];
    ifstream in(filename);
    list<string> lst;

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
	            lst.push_back(nopunct);
                tokens.push_back(nopunct);
		        unique.insert(nopunct);
		    // cout << token<<endl;
	    }
    }
    // cout << "Number of words "<<tokens.size()<<endl;
    // cout << "Number of words (list) "<< lst.size()<<endl;
//     cout << "Number of unique words (vector) "<< unique.size()<<endl;
// }

    // create set file
    // createSetFile(filename, unique);
    ofstream setfile(filename + "_set.txt");

    for (set<string>::iterator it=unique.begin(); it!=unique.end(); ++it){
        // cout << ' ' << *it;
        setfile << ' ' << *it;
    }
    setfile.close();

    // create vector file
    // createVectorFile(filename, tokens);
    ofstream vectorfile(filename + "_vector.txt");
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); ++it){
        vectorfile <<  *it << endl;
    }
    vectorfile.close();

    // create map file
    // makeMapFile(tokens, filename);
    map<string, string> wordmapDoc;
    string last=" ";
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmapDoc[last]=*it;
        last = *it;
    }
    ofstream mapfile(filename + "_map.txt");
    
    for (auto it = wordmapDoc.begin(); it != wordmapDoc.end(); it++) {
        mapfile << it->first << ", " << it->second << endl;
    }
    mapfile.close();


    // Generate Boring Text
    // string state = "";
    // for(int i = 0; i < 100; i++){
    //     cout << wordmap[state] << " ";
    //     state = wordmap[state];
    // }
    // cout << endl;

    // Generate Interesting Text
    map<string, vector<string>> wordmap;
    string state = "";
    for(vector<string>::iterator it=tokens.begin(); it !=tokens.end(); it++) {
        wordmap[state].push_back(*it);

        state = *it;
    }
    // cout << "" << endl;
    // cout << "The vector of strings that match the key \"Nephi\": " << endl;
    // // // // verify the output for "Nephi" is the same as given in the lab instructions
    // for(map<string, vector<string>>::iterator itr = wordmap.begin(); itr != wordmap.end(); itr++) {
    //     if(itr->first == "Nephi") {
    //         //print out the vector of strings that match the key "Nephi"
            
    //         for(int i = 0; i < itr->second.size(); i++) {
    //             cout << itr->second[i] << ", ";
    //         }
    //         cout << endl;
    //     } 
    // }

    // print out the vector of words that correspond to the 6th entry in the map (accessed using an iterator).
    // int counter = 0;
    // cout << "" << endl;
    // cout << "The vector of words that correspond to the 6th entry in the map: " << endl;
    // for(map<string, vector<string>>::iterator it = wordmap.begin(); it != wordmap.end(); it++) {
    //     if(counter == 6) {
            
    //         for(int i = 0; i < it->second.size(); i++) {
    //             cout << it->second[i] << ", ";
    //         }
    //         cout << endl;  
    //         break;
    //     }
    //     counter ++;
    // }

    // cout << "" << endl;
    // cout << "More interesting text: " << endl;  
    // srand(time(NULL)); // this line initializes the random number generated
    //                // so you dont get the same thing every time
    // state = "";
    // for (int i = 0; i < 100; i++) {
    //     int ind = rand() % wordmap[state].size();
    //     cout << wordmap[state][ind] << " ";
    //     state = wordmap[state][ind];
    // }
    cout << endl;

    cout << endl;
    cout << "Smarter Text: " << endl;
    ///////// Part 6 ////////////
    const int M = 2;
    map<list<string>, vector<string>> wordmap6;
    list<string> state2;
    for (int i = 0; i < M; i++) {
        state2.push_back("");
    }
                            
    for (vector<string>::iterator it=tokens.begin(); it!=tokens.end(); it++) {
        wordmap6[state2].push_back(*it);
        state2.push_back(*it);
        state2.pop_front();
    }

    state2.clear();
    for (int i = 0; i < M; i++) {
        state2.push_back("");
    }
    for (int i = 0; i < 250; i++) {
        int ind = rand() % wordmap6[state2].size();
        cout << wordmap6[state2][ind]<<" ";
        state2.push_back(wordmap6[state2][ind]);
        state2.pop_front();
    }
    cout << endl;
    
    return 0;
}