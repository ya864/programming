<?php
    $n = trim(fgets(STDIN));
    $ans = 0;
    
    for($i = 0 ; $i < $n ; $i++)
    {
        $input = trim(fgets(STDIN));
        $input = explode(" ", $input);
        
        $score = array();
        for($j = 1 ; $j < 6 ; $j++)
        {
            $score[] = $input[$j];
        }
        $sum = array_sum($score);
        $l = $score[3] + $score[4];
        $s = $score[1] + $score[2];

        if($sum >= 350)
        {
            if($input[0] == "l" && $l >= 160) $ans++;
            if($input[0] == "s" && $s >= 160) $ans++;
        }
    }
    echo $ans."\n";
?>
