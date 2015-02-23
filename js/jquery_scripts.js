jQuery(document).ready(function($){


	jQuery("div.kin_content_toggle_div").click(function(){
		$("div.toggled_content").slideToggle( "slow", function() {});
	});

	jQuery("div.oracle_content_toggle_div").click(function(){
		$("div.toggled_oracle_content").slideToggle( "fast ", function() {});
	});

});

