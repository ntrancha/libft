<?php
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_date.php                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntrancha <ntrancha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/08 15:43:35 by ntrancha          #+#    #+#             */
/*   Updated: 2015/08/08 15:43:35 by ntrancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

function test_date($h, $i, $s, $m, $d, $y)
{
    $timestamp = mktime($h, $i, $s, $m, $d, $y);
    $commandes = './a.out "'.$h.":".$i.":".$s." ".$d."/".$m."/".$y.'"';
    $prog = exec($commandes);
    if ($prog != $timestamp)
    {
        echo $prog." ".$timestamp;
        if ($prog > $timestamp)
            echo " > ";
        else
            echo " < ";
                    echo "$y $m $d a $h heure\n";
        exit;
        return 0;
    }
    /*echo $prog."           :";
    echo "$y $m $d a $h heure\n";*/
    return 1;
}

$y = 1970;
while ($y < 2055)
{
    $m = 3;
    while ($m < 11)
    {
        $d = 1;
        while ($d < 27)
        {
            $h = 0;
            while ($h < 23)
                {
                    test_date($h, 2, 50, $m, $d, $y);
                    $h++;
                }
            $d++;
        }
        $m++;
    }
    echo "$y OK\n";
    $y++;
}
?>

