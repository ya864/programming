<?php
    $input = trim(fgets(STDIN));
    $input = explode(" ", $input);
    $n = $input[0];
    $m = $input[1];

    $strs = array();
    for($i = 0 ; $i < $n ; $i++)
    {
        $input = trim(fgets(STDIN));
        $input = explode(" ", $input);
        if(array_key_exists($input[0], $strs))
        {
            $strs[$input[0]] += $input[1];
        }
        else
        {
            $strs[$input[0]] = $input[1];
        }

    }
    ksort($strs);
    $keys = array_keys($strs);
    $values = array_values($strs);
    $cnt = 0;

    for($i = 0 ; $i < $m ; $i++)
    {
        $input = trim(fgets(STDIN));
        $start = startSearch($input, $keys);
        $end = endSearch($input, $keys);
        $cnt = valueSum($start, $end, $values);
        echo $cnt."\n";
    }


    function startSearch($target, $keys)
    {
        $left = 0;
        $right = count($keys);

        while($left < $right)
        {
            $mid = floor(($left + $right) / 2);
            if($keys[$mid] >= $target)
            {
                $right = $mid;
            }
            else
            {
                $left = $mid+1;
            }
        }
        return $left;
    }

    function endSearch($target, $keys)
    {
        $left = 0;
        $right = count($keys);

        while($left < $right)
        {
            $mid = floor(($left + $right) / 2);
            if($keys[$mid] >= $target && substr($keys[$mid], 0, strlen($target)) === $target)
            {
                $left = $mid+1;
            }
            else if($keys[$mid] > $target)
            {
                $right = $mid;
            }
            else
            {
                $left = $mid+1;
            }
        }
        return $right;
    }

    function valueSum($start, $end, $values)
    {
        $cnt = 0;
        for($i = $start ; $i < $end ; $i++)
        {
            $cnt += $values[$i];
        }
        return $cnt;
    }
?>
