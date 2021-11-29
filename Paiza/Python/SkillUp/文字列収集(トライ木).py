ALPHABETS_NUM = 26
class TrieNode:
    """
    Trie木の1ノードを表すクラス
    """

    def __init__(self, value = 0):
        self.value = value
        self.children = [-1 for i in range(ALPHABETS_NUM)]

class Trie:
    """
    Trie木を表すクラス
    """
    def __init__(self):
        root = TrieNode()
        self.nodes = [root]

    def __add_node(self, node):
        """
        nodesにノードを追加する
        """
        self.nodes.append(node)
        return len(self.nodes) - 1

    def __get_char_num(self, c):
        """
        文字のidを返す
        """
        return ord(c) - ord('a')

    def search(self,word):
        node_index = 0
        val = 0
        # 渡された文字列の最後までノードが存在するか検索する
        for c in word:
            char_num = self.__get_char_num(c)
            tmp_node = self.nodes[node_index]
            node_index = tmp_node.children[char_num]
        
        # 存在しない場合は検索を終了
        if node_index == -1:
            return val
        
        # 渡された文字列をprefixとした文字列が存在するか検索し、値を合計していく
        index_array = []
        index_array.append(node_index)
        while len(index_array) > 0:
            next_index = index_array.pop()
            next_node = self.nodes[next_index]
            val += next_node.value
            for i in range(ALPHABETS_NUM):
                if next_node.children[i] != -1:
                    index_array.append(next_node.children[i])
        return val
                
    def insert(self, word, value, char_index=0, node_index=0):
        """
        Trie木に新しい単語を登録する
        """
        char_num = self.__get_char_num(word[char_index])
        next_node_index = self.nodes[node_index].children[char_num]
        if next_node_index == -1:
            # 現在のノードにword[char_index]での遷移が存在しない場合
            new_node = TrieNode()
            next_node_index = self.__add_node(new_node)
            self.nodes[node_index].children[char_num] = next_node_index

        if char_index == len(word) - 1:
            # 最後の文字だった場合
            self.nodes[next_node_index].value += int(value)
        else:
            self.insert(word, value, char_index+1, next_node_index)

    # デバッグ用
    def print(self):
        for i in range(len(self.nodes) - 1):
            print(vars(self.nodes[i]))
        
        
N,M = map(int, input().split())
trie = Trie()

for i in range(N):
    word, value = input().split()
    trie.insert(word, value)

for i in range(M):
    target = input()
    print(trie.search(target))