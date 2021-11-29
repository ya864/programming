<?php
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $n = $input[0];
    $k = $input[1];

    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $balls = $input;

    // ボールを大きさで昇順にソート
    sort($balls);
    $cnt = 0;
    $end = count($balls)-1;

    /*
      使っていないボールの中で、一番小さいものと大きいものを合わせる。
      与えられた$kより大きければ、大きいもののボールを使用済みにするために、$endを−１する。
      小さいものについてはfor文でプラスしていくので、特に数字にプラスしたりしない。

      for文の条件式に$endを使って、同じボールで組み合わせを試行しないようにしている。
    */
    for($i = 0 ; $i < $end ; $i++)
    {
        if($balls[$i] + $balls[$end] >= $k)
        {
            $end--;
            $cnt++;
        }
    }

    echo $cnt;
?>
