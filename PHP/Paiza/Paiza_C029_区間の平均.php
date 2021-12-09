<?php
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $M = $input[0];
    $N = $input[1];
    
    $days = array();
    $rain = array();
    
    for($i = 0 ; $i < $M ; $i++)
    {
        $input = trim(fgets(STDIN));
        $input = explode(" ", $input);
        $days[] = $input[0];
        $rain[] = $input[1];
    }
    
    $d = 0;
    $e = 0;
    $min = 999999999;
    // $i < $M-$N+1 にしないと全ての日数を計算できない
    for($i = 0 ; $i < $M-$N+1 ; $i++)
    {
        $avg = 0;
        for($j = 0 ; $j < $N ; $j++)
        {
            $avg += $rain[$i + $j];
        }
        $avg = $avg / $N;
        if($avg < $min)
        {
            $min = $avg;
            $d = $days[$i];
            $e = $days[$i+$N-1];
        }
    }
    
    echo $d." ".$e."\n";
?>
