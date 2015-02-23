<?php // cal_show_kin_info.inc


// Start Pop Content
$popup_content = "";


// Show Kin Images ... maybe they need to make room for portal image
if ($portals !== ""){
	$popup_content .= "<div class=\"kin_tainer\" id=\"kin_tainer_id\" style=\"min-width: 180px;\">";
} else {
	$popup_content .= "<div class=\"kin_tainer\" id=\"kin_tainer_id\" style=\"min-width: 133px;\">";
}

$popup_content .= "<div class=\"kin_content_toggle_div\">";

$popup_content .= "<div class=\"tone_image\">";
$popup_content .= "<img src=\"$tones_img_dir/$tone_image\" alt=\"$tone_name\" class=\"tone_img\">";
$popup_content .= "</div>\n\n";

$popup_content .= "<div class=\"seal_image\">";
$popup_content .= "<img src=\"$seals_img_dir/$seal_image\" alt=\"$seal_name\" class=\"seal_img\">";
$popup_content .= "</div>\n";


// Portal Info
if ($portals != ""){
    	$popup_content .= "<div class=\"portal_image_div\" id=\"portal_image_id\" >";
    	$popup_content .= "<img src=\"$portals_img_dir/portals_trans.gif\" alt=\"Galactic Portal Day\">";
    	$popup_content .= "</div>\n\n";
}

$popup_content .= "</div>\n";
$popup_content .= "</div>\n";


// Wrap the whole thing in a disappearing div
$popup_content .= "<div class=\"toggled_content\">";

// Show Kin Number and Text
$popup_content .= "<div class=\"kinfo_tainer\">";
$popup_content .= "<div class=\"kin_num\">Kin $this_day_kin_num</div>";
$popup_content .= "<div class=\"color_tone_tribe\">$color_name $tone_name $seal_name</div>\n";
$popup_content .= "</div>\n";

// Show affirmation for this Kin
$popup_content .= "<div class=\"kin_affirm\">";
$popup_content .= "$affirm_one<br>$affirm_two<br>$affirm_three<br>$affirm_four<br>$affirm_five";
if ($polar_kin === ""){}else{$popup_content .= "<br>$polar_kin";}
if ($portals  === ""){}else{$popup_content .= "<br>$affirm_six";}
$popup_content .= "</div>\n\n";

// Castle info
$popup_content .= "<div class=\"castle_class\">";
$popup_content .= "$this_castle_affirm";
$popup_content .= "</div>\n\n";


// Wevespell Info
$popup_content .= "<div class=\"wave_spl\">";
$popup_content .= "$this_wavespell_affirm";
$popup_content .= "</div>\n\n";

// Wrap the whole thing in a TOGGLE div
$popup_content .= "</div>\n\n";


// Link to SSP -- need to get options before we can display this
if ($show_famous_events === "YES"){
	$seo_sig = tmc_translate_kin_to_seo($this_day_kin_num);
    	$ssp_link = "<a class=\"ssp_link\" href=\"http://spacestationplaza.com/13-moon-dreamspell-calendar/$seo_sig\" target=\"_blank\">";
    	$popup_content .= "<div class=\"ssp_ext_link\">";
    	$popup_content .= $ssp_link."Famous Kin ".$this_day_kin_num."</a>";
    	$popup_content .= "</div>\n\n";
}

echo "$popup_content";

?>