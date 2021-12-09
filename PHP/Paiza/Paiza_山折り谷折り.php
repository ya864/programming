<?php
    $n = trim(fgets(STDIN));
    $arr = array();
    $arr[] = 0;
    
    folding($n-1);
    
    foreach($arr as $ans)
    {
        echo $ans;
    }
    
    /*
        n回、紙を一方向に折りたたんでいくというのは、谷を０、山を１とすると、
        １回目は０になり、２回目は００１、３回目は００１００１１になる。
        配列に数字を格納した後、各要素の間に０と１を交互に挟んでいくことで表現できる。
    */

    function folding($n)
    {
        if($n > 0)
        {
            global $arr;    
            $arr2 = $arr;
            $arr = array();

            $arr[] = 0;
            for($i = 0 ; $i < count($arr2) ; $i++)
            {
                $arr[] = $arr2[$i];
                if($i % 2 == 0)
                {
                    $arr[] = 1;
                }
                else
                {
                    $arr[] = 0;
                }
            }
            folding($n-1);
        }
    }
    
?>
