#include <solution.h>

const int KEY_RANGE = 26;

Trie::Trie(){}

Trie::~Trie(){
	if(m_pChildren == nullptr){
		delete[] m_pChildren;
	}
}

/** Inserts a word into the trie. */
void Trie::insert(string word){
	if(nullptr == m_pChildren){
		m_pChildren = new Trie[KEY_RANGE];
	}

	int index = word[0] - 'a';
	m_pChildren[index].m_value = word[0];
	if(word.length() == 1){
		m_pChildren[index].m_bKey = true;
	}
	else{
		m_pChildren[index].insert(word.substr(1));
	}
}

/** Returns if the word is in the trie. */
bool Trie::search(string word){
	if(m_pChildren == nullptr){
		return false;
	}

	int index = word[0] - 'a';
	if(m_pChildren[index].m_value == word[0]){
		if(word.length() == 1){
			return m_pChildren[index].m_bKey;
		}
		else{
			return m_pChildren[index].search(word.substr(1));
		}
	}
	else{
		return false;
	}
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool Trie::startsWith(string prefix){
	if(m_pChildren == nullptr){
		return false;
	}

	int index = prefix[0] - 'a';
	if(m_pChildren[index].m_value == prefix[0]){
		if(prefix.length() == 1){
			return true;
		}
		else{
			return m_pChildren[index].startsWith(prefix.substr(1));
		}
	}
	else{
		return false;
	}
}
