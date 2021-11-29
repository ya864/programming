<?php
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $n = $input[0];
    $m = $input[1];

    $input = trim(fgets(STDIN));
    /*
      事前に与えられた文字列に出現する文字をカウントしておく
    */
    $G = mb_substr_count($input, "G");
    $C = mb_substr_count($input, "C");
    $P = mb_substr_count($input, "P");

    $c = array();
    $p = array();

    /*
      グーの時には指の数に変化は出ないので、チョキとパーの組み合わせを
      事前に配列に格納しておく。
    */
    for($i = 0 ; $i <= $n ; $i++)
    {
        for($j = 0 ; $j <= $n ; $j++)
        {
            if(2*$i + 5*$j == $m && $n - $i - $j >= 0)
            {
                $c[] = $i;
                $p[] = $j;
            }
        }
    }

    $ans = 0;
    /*
      格納した組み合わせの要素が０になるまで繰り返す
    */
    while(count($c) > 0)
    {
        $win = 0;
        // 配列からデキューして取り出す
        $cc = array_shift($c);
        $pp = array_shift($p);

        /*
          取り出した組み合わせと対戦相手の手を比較して、勝利数を計算する
          パーとグーの数を数えて、少ないほうが結果的に勝利数となるので、
          こちらが勝てる組み合わせで数の少ない方を勝利数にプラスする。
        */
        $win += min($G, $pp);
        $win += min($P, $cc);
        $win += min($C, $n - $cc - $pp);

        //　計算した$winと$ansを比較して大きい方を$ansに代入
        // これによって一番勝利数が多い時を求められる
        $ans = max($ans, $win);
    }

    echo $ans;
?>
