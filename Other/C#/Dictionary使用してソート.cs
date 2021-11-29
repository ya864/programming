/*
ここは株式会社 人月査定。

人月査定では、開発者の離職が課題になっていました。


調査してみると、優秀な開発者から順に離職していることがわかりました。

その原因を調査すると、どうやら多くの成果物を生み出す優秀な開発者と

ほとんど成果物を生み出していない開発者の給与が全く同じであるためでした。


そこで人月査定では成果主義による評価制度を導入することを決定しました。

社名も株式会社 ステップ数見積もり に変更です。


こうして社内特命プロジェクト「おちんぎんあっぷ大作戦」が始動しました。


「ステップ数見積もり社」ではバージョン管理ツールKit（きっと）でプログラムの履歴管理をしています。

Kitの履歴をもとに「どの開発者が何%の成果物を仕上げているか？」を調べてください。


Kitの履歴は1ファイル1行単位で残ります。

1つの履歴を保存することをコミットと呼びます。

コミット履歴は20件しか残りません。仕様です。




標準入力

Kitの履歴が標準入力されます


・コミットした開発者名、ファイル名がカンマ区切りで入力されます

・コミットした開発者名は [a-z] の文字列で構成されます

・コミットした開発者名は 3-8 文字です

・開発対象は「hoge.rb hige.rb hage.rb hoo.rb bar.rb」の5ファイルです

・入力データは20件


例（サンプルのため入力が3件ですが、実際は20件入力されます）

horiuchi,hoge.rb
hironaka,hige.rb
kondo,hoo.rb




標準出力

・出力形式は コミットした開発者名 + 半角コロン(:) + コミットしたファイルのパーセンテージ + 半角パーセント(%) です

・パーセンテージは小数点以下を切り捨ててください


例（標準入力の説明の入力が行われた場合の出力結果）

hironaka:33%
horiuchi:33%
kondo:33%




その他の仕様

・標準入力の末尾には改行があります

・標準出力の末尾に改行をつけてください

・同じファイルを複数の開発者が更新した場合、最後にファイルを更新した人がその成果物を仕上げた人としてください

　例えば hoge.rb を tanaka さん、 suzuki さん、 sato さんの順番で更新していたら

　hoge.rb の開発者は sato さんとして集計します

・標準入力の後半の行に出たほうが後から更新しているものとします

・標準入力の仕様で説明した内容以外の入力は行われません（不正入力に対するチェックは不要）

・出力は人名辞書順でソートしてください

・成果がない人は出力対象外としてください

・1度もコミットがないファイルがあった場合、%の母数には含まないものとします



*/

using System;
using System.Collections.Generic;
using System.Linq;


public class Test
{
	public static void Main()
	{
		string[] hito = new string[20];
		string[] file = new string[20];
		int[] parsent = new int[20];
		int a = 0;
		Dictionary<string,int> dict = new Dictionary<string,int>();
		
		string line;
		for(;(line = Console.ReadLine())!=null;){		
			string[] buffer = line.Split(',');
			hito[a] = buffer[0];
			file[a] = buffer[1];
			a++;	
        }
		
		for(int x=19;x>0;x--){
			for(int y=x-1;y>0;y--){
				if(file[x]==file[y]){
					hito[y] = null;
				}
			}		
		}		
		
		for(int x=19;x>0;x--){
			for(int y=x-1;y>0;y--){
				if(hito[x]==hito[y]){
					parsent[x]++;
					hito[y]= null;
				}
			}		
		}	
		for(int x=19;x>0;x--){
			if(hito[x]!=null){
					dict.Add(hito[x],parsent[x]+1);
			}
		}
		// Dictionaryの値を合計するために配列にコピー。もっと上手いやり方があるはず。
		int[] par = new int[dict.Keys.Count];
		dict.Values.CopyTo(par, 0);
		// この部分はどこを参考にするでもなく、配列の中身の合計を書くことができた。よかった。
		int sum = 0;
		foreach (var n in par){
			sum = sum +n;
		}
		//　↓Dictionaryを使用してソート。名前の順。
		var sorted = dict.OrderBy((x) => x.Key); 
		foreach (var p in sorted)//ソート後のDictionaryを列挙
            {
                Console.WriteLine(string.Format("{0}:{1}%", p.Key, p.Value*(100/sum)));
            }

	}
}