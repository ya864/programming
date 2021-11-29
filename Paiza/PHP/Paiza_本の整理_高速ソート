<?php
    $n = trim(fgets(STDIN));
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);

    $books = $input;
    $cnt = 0;
    $a = 0;
    $b = 0;

    /*
      問題のままだと$booksの値をそのまま配列に使えないので、
      事前にすべて−１しておく。
    */
    for($i = 0 ; $i < count($books) ; $i++)
    {
        $books[$i]--;
    }

    /*
      この問題はC#だと通常のバブルソートの交換回数を数えるだけで良かったが、
      PHPだと処理速度の問題でTEになってしまう。

      取り出した本を入れ替え続けて、元の場所($i)に戻って来た時に、
      ループを終了させるようにした。
      バブルソートの回数を数えるよりも２０倍程度高速化できた。
    */
    for($i = 0 ; $i < $n ; $i++)
    {
        if($books[$i] != $i)
        {
            $a = $books[$i];
            $b = -1;
            while($a != $i)
            {
                $b = $books[$a];
                $books[$a] = $a;
                $a = $b;
                $cnt++;
            }
            $books[$a] = $a;
        }
    }

    echo $cnt;
?>
