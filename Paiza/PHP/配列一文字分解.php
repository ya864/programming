
/*
    配列の 要素を文字列と同じように連接する。
    連接され　た要素を一文字ずつに配列として格納する。

*/


<?php
    solve();
    function solve(){
        $N = trim(fgets(STDIN));
        $N = explode(" ",$N);
        // 配列の要素を文字列のように連結
        $s = $N[0].$N[1];
        
        // 連結した要素を一文字ずつに分解し、配列に格納
        $A = str_split($s);
        $no = 0;

        for($i = 0 ; $i < count($A) ; $i++)
        {
            for($j = $i+1 ; $j < count($A) ;$j++)
            {
                if($A[$i] != $A[$j])
                {
                    $no++;
                }
            }
        }
        if($no == 0) echo "Yes";
        else echo "No";
    }
?>

