#include<iostream>
#include<string>	

// abcabcabcaabb -> a5b5c3

using namespace std;

// ѕосчитать максимальную последовательность
// одинаковых символов в строке
// "aaaaabbccccccccccccc" => c -> 13,
// "aabb" => b -> 2,
// "abc" -> 0
void printMaxCharInString(string str) {
	int max = 0;
	int currentCount = 0;
	char maxChar = char(205);

	for (int i = 0; i < str.size(); i++) {
		currentCount++;

		if (str[i] != str[i + 1]) {
			if (max <= currentCount) {
				maxChar = str[i];
				max = currentCount;
			}
			currentCount = 0;
		}
	}

	maxChar != char(205) && max > 1
		? cout << maxChar << " -> " << max
		: cout << 0;
}

bool isNotUniq(string str, char symbol) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == symbol) return true;
	}

	return false;
}

// ѕосчитать сколько раз символ встречаетс€ в строке
// и вывести это новой строкой
// abcabcabcaabb -> a5b5c3
// aaabbc -> a3b2c1
// bbaaccb -> b3a2c2
void printCharCountForString(string str) {
	int counter = 1;
	string uniq, result;

	for (int i = 0; i < str.size(); i++) {
		// str[3] = "b" (4)
		bool isNotUn = false; // uniq = ""; uniq = "a" (2, 3)
		// uniq = "ab" (4)

		for (int k = 0; k < uniq.size(); k++) {
			if (uniq[k] == str[i]) isNotUn = true;
		}

		if (isNotUniq(uniq, str[i])) continue; // uniq = "" ->

		uniq += str[i]; // uniq = str[i] (1) , uniq = "a"
		// uniq = "ab"

		for (int j = i + 1; j < str.size(); j++) {
			if (str[j] == str[i]) {
				counter++;
			}
		}

		result += (str[i] + to_string(counter)); // result = "a4"
		counter = 1;
		// uniq = "a" '// uniq = "ab"
		// result = "a4" // result = "a4b4"
	}

	cout << "resultStr = " << result << endl;
}

int main() {
	string s = "aabbffccaabb";
	cout << "origin str = " << s << endl;
	//printMaxCharInString(s);
	printCharCountForString(s);

	return 0;
}