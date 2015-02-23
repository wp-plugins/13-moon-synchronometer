<?php // cal_maya_days_row.php

// show days of week at top

$day_count = 1;
while ($day_count <= 7){

// To get the maya name of day, it's simply 1-7, each with a name: 
	$maya_day_name = gday_nam_to_may_name($day_count);

// use the value we set in cal_build_table.inc to determine the Plasma for today

$what_is_today = tm_day_num_to_plasma_num($hightlight_plasma_today);

if ($what_is_today == $day_count){
	$hightlight_plasma = "hlt";
} else {
	$hightlight_plasma = "norm";
}

// $hightlight_plasma = "hlt";
// Make a title for the plasma
	$plasma_title = "title=\"$this_moon_name $maya_day_name\"";
	echo "<td class=\"cal_row_med_norm\">\n";
	echo "<div title=\"$day_count - $maya_day_name\" style=\"padding: 0px; line-height: 8px;\">";
	echo "<a href=\"$ajax_info?height=150&amp;width=200&amp;day_num=$day_count&amp;maya_day_name=$maya_day_name&amp;purl=".plugins_url()."\" title=\"$maya_day_name\" class=\"thickbox\">";
	echo "<img class=\"plasma_icons\" src=\"$plasmas_img_dir/$maya_day_name".".png\" alt=\"$maya_day_name\" width=24 height=24 style=\"padding-top: 1px;\" $plasma_title>";
	echo "</a>";
	echo "</div>";
	echo "</td>";
	$day_count++;
}

?>