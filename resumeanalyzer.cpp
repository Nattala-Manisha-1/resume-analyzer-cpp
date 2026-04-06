#include <bits/stdc++.h>
using namespace std;

// Convert to lowercase
string toLower(string s) {
    for (char &c : s) c = tolower(c);
    return s;
}

// Read file
string readFile(string filename) {
    ifstream file(filename);
    string line, content = "";
    while (getline(file, line)) {
        content += line + " ";
    }
    return toLower(content);
}

// Count occurrences of a word
int countOccurrences(string text, string word) {
    int count = 0;
    size_t pos = 0;

    while ((pos = text.find(word, pos)) != string::npos) {
        count++;
        pos += word.length();
    }
    return count;
}

int main() {
    cout << "Select Job Role:\n";
    cout << "1. Software Developer\n";
    cout << "2. Data Analyst\n";
    int choice;
    cin >> choice;

    // Role-based skills
    vector<string> skills;

    if (choice == 1) {
        skills = {"c++", "java", "python", "data structures", "algorithms", "oop", "dbms"};
    } else {
        skills = {"python", "sql", "excel", "machine learning", "statistics", "power bi"};
    }

    // Read resume
    string resume = readFile("resume.txt");

    int score = 0;
    vector<pair<string, int>> found;
    vector<string> missing;

    // Analyze
    for (string skill : skills) {
        int freq = countOccurrences(resume, skill);

        if (freq > 0) {
            score += min(freq * 10, 20); // weighted scoring
            found.push_back({skill, freq});
        } else {
            missing.push_back(skill);
        }
    }

    if (score > 100) score = 100;

    // Output
    cout << "\n===== SMART RESUME ANALYSIS =====\n";
    cout << "\nScore: " << score << "/100\n";

    cout << "\n✅ Skills Found (with frequency):\n";
    for (auto &p : found) {
        cout << "- " << p.first << " (" << p.second << " times)\n";
    }

    cout << "\n❌ Missing Skills:\n";
    for (string s : missing) {
        cout << "- " << s << endl;
    }

    cout << "\n💡 Suggestions:\n";
    if (!missing.empty()) {
        cout << "Add these skills to improve your resume:\n";
        for (string s : missing) {
            cout << "- " << s << endl;
        }
    } else {
        cout << "Excellent! Your resume matches the role well.\n";
    }

    return 0;
}