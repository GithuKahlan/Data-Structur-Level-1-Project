#pragma once
#include<iostream>
#include<vector>
using namespace std;

class clsString
{
public:

private:
	string Value;

public:

	clsString()
	{
		Value = "";
	}


	clsString(string value)
	{
		Value = value;

	}

	void SetValue(string value)
	{
		Value = value;
	}

	string GetValue()
	{
		return Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string value;


	static short Length(string S1)
	{
		return S1.length();

	}

	short Length()
	{
		return Value.length();
	}


	static short CountWords(string S1)
	{
		string delim = " ";
		short Counter = 0;
		short pos = 0;
		string sWord;
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);
			if (sWord != "")
			{
				Counter++;

			}

			S1.erase(0, pos + delim.length());
		}

		if (S1 != "")
		{
			Counter++;
		}

		return Counter;
	}

	short CountWords()
	{

		return CountWords(Value);
	};

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
				S1[i] = toupper(S1[i]);
			isFirstLetter = (S1[i] == ' ' ? true : false);

		}
		return S1;
	}

	void UpperFirstLetterOfEachWord()
	{
		Value = UpperFirstLetterOfEachWord(Value);

	};



	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ' && isFirstLetter)
				S1[i] = tolower(S1[i]);
			isFirstLetter = (S1[i] == ' ' ? true : false);

		}
		return S1;
	}

	void LowerFirstLetterOfEachWord()
	{
		Value = LowerFirstLetterOfEachWord(Value);

	};




	static string UpperAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = toupper(S1[i]);

		}
		return S1;
	}

	void UpperAllString()
	{
		Value = UpperAllString(Value);

	};



	static string LowerAllString(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);

		}
		return S1;
	}

	void LowerAllString()
	{
		Value = LowerAllString(Value);

	};


	static char InvertLetterCase(char Char1)
	{
		return isupper(Char1) ? tolower(Char1) : toupper(Char1);

	}

	static string InvertAllLetterCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;

	}


	void InvertAllLetterCase()
	{
		Value = InvertAllLetterCase(Value);


	}


	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
		{
			return S1.length();
		}

		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
				Counter++;
		}

		return Counter;
	}

	static short CountCapitalLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
				Counter++;
		}
		return Counter;

	}

	short CountCapitalLetters()
	{

		return CountCapitalLetters(Value);

	}


	static short CountSmallLetters(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
				Counter++;
		}
		return Counter;

	}

	short CountSmallLetters()
	{

		return CountSmallLetters(Value);

	}

	static short CounteSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if ((Letter == S1[i]))
					Counter++;
			}

			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}


	short CounteSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CounteSpecificLetter(Value, Letter, MatchCase);

	}


	static bool IsVowel(char Ch1)
	{

		Ch1 = tolower(Ch1);
		return((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));

	}


	static short CountVowels(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (IsVowel(S1[i]))
				Counter++;


		}
		return Counter;

	}


	short CountVowels()
	{
		return CountVowels(Value);
	}

	static vector<string> Split(string S1, string Delim)
	{

		vector<string>Vstring;
		short pos = 0;
		string sWord;

		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos);

			if (sWord != "")
			{
				Vstring.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length());
		}

		if (S1 != "")
		{
			Vstring.push_back(S1);
		}

		return Vstring;
	}

	vector<string>Split(string Delim)
	{
		return Split(Value, Delim);
	}


	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);
			}
		}
		return"";
	}

	void TrimLeft()
	{
		Value = TrimLeft(Value);

	}


	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return"";
	}

	void TrimRight()
	{
		Value = TrimRight(Value);

	}


	static string Trim(string S1)
	{
		return(TrimLeft(TrimRight(S1)));

	}

	void Trim()
	{
		Value = Trim(Value);

	}


	static string JoinString(vector<string>vString, string Delim)
	{
		string S1 = "";

		for (string& s : vString)
		{
			S1 = S1 + s + Delim;

		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string JoinString(string arrString[], short Length, string Delim)
	{
		string S1 = "";

		for (short i = 0; i < Length; i++)
		{
			S1 = S1 + arrString[i] + Delim;

		}

		return S1.substr(0, S1.length() - Delim.length());

	}

	static string ReverseWordInString(string S1)
	{
		vector<string>vString;
		string S2 = "";
		vString = Split(S1, " ");

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}

		S2 = S2.substr(0, S2.length() - 1);

		return S2;

	}

	void ReverseWordInString()
	{
		Value = ReverseWordInString(Value);


	}

	static string ReplaceWord(string S1, string StringToReplace, string sReplaceTo, bool MathCase = true)
	{
		vector<string>vString = Split(S1, " ");

		for (string& s : vString)
		{
			if (MathCase)
			{
				if (s == StringToReplace)
				{
					s = sReplaceTo;

				}
			}

			else
			{

				if (LowerAllString(s) == LowerAllString(StringToReplace))
				{
					s = sReplaceTo;

				}

			}

		}

		return JoinString(vString, " ");

	}

	string ReplaceWord(string StringToReplace, string sReplaceTo)
	{
		return ReplaceWord(Value, StringToReplace, sReplaceTo);

	}

	static string RemovePunctuations(string S1)
	{
		string S2 = "";

		for (short i = 0; i < S1.length(); i++)
		{
			if (!ispunct(S1[i]))
			{
				S2 += S1[i];
			}
		}

		return S2;
	}

	void RemovePunctuations()
	{
		Value = RemovePunctuations(Value);

	}

};

