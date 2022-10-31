<?php
/**
 * @file
 * swaylocks_marketing.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function swaylocks_marketing_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Default Footer';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_content';
  $fe_block_boxes->body = '<style type="text/css">#footer {
 background-color: #FFF;
 color: #555;
 line-height: 1.5em;
 border-top: 1px solid #CCC;
 font-family: "heebo";
}
#footer .row {
  padding: 1em;
}
#footer .block {
  width: 100%;
}
#footer h3 {
 margin-bottom: 0.3em;
}
#footer ul {
  padding-left: 0px;
}
.link_button { 
  background: none;
  border: none;
  color: #348bc2;
  text-decoration: none;
  cursor: pointer;
  padding: 0;  
}
</style>
<div class="row">
<div class="col-md-4"><a href="/" rel="home" style="background: url(/sites/default/themes/forum_plus/images/logo.svg) no-repeat; height: 26px; left: 15px; top: 0px; position: absolute; width: 135px; z-index: 10;" title="Back to Home"><span style="display:none;">Swaylock\'s Surfboard Design Forum</span></a>
<div style="padding-top: 2.5em;">
<p>©1999-2020&nbsp;Swaylocks.com - All rights reserved</p>

<p>Swaylock\'s and Quiver are registered trademarks of Swaylocks.com</p>
</div>
</div>

<div class="col-md-4" style="border-left: 1px solid #CCC; border-right: 1px solid #CCC;">
<p><strong>Handy Links</strong></p>

<ul>
	<li class="first leaf"><a href="/contact">Contact</a></li>
	<li class="leaf"><a href="/advertise" title="Advertise on Swaylocks.com">Advertise on Swaylock\'s</a></li>
	<li class="leaf"><a href="/privacy-policy" title="Swaylock\'s Privacy Policy">Privacy Policy</a></li>
	<li class="last leaf"><a href="/terms">Terms of Use</a></li>
</ul>
</div>

<div class="col-md-4">
<p><strong>Donate</strong></p>

<ul>
	<li class="leaf">
	<form action="https://www.paypal.com/cgi-bin/webscr" id="donate" method="post" target="_top"><input name="cmd" type="hidden" value="_s-xclick" /> <input name="hosted_button_id" type="hidden" value="22WSG2YKQR87C" /> <input alt="PayPal - The safer, easier way to pay online!" border="0" class="link_button" name="submit" type="submit" value="PayPal" /> <img alt="" border="0" height="1" src="https://www.paypalobjects.com/en_US/i/scr/pixel.gif" width="1" /></form>
	</li>
	<li class="leaf">BTC:&nbsp;<a href="https://www.blockchain.com/btc/payment_request?address=3EB67Y8gtcTbNN5UzB9kiKP3N2k1zVjfBt" target="_blank">3EB67Y8gtcTbNN5UzB9kiKP3N2k1zVjfBt</a></li>
	<li class="leaf">ETH:&nbsp;<a href="https://etherscan.io/address/0xce50b20133612101f9d2bf4bc2cbdf71f6465f95" target="_blank">0xcE50B20133612101F9d2BF4bc2CBdf71F6465f95</a></li>
	<li class="leaf">LTC:&nbsp;<a href="https://chainz.cryptoid.info/ltc/search.dws?q=LQq3j5YdYAmormBfY77woRsdd4dYRFYMjL" target="_blank">LQq3j5YdYAmormBfY77woRsdd4dYRFYMjL</a></li>
</ul>

<p><strong>Buy Cryptocurrency</strong></p>
<a href="https://www.coinbase.com/join/5a3df0c2424fc40314329a0e" target="_blank">Coinbase</a> | <a href="https://changelly.com/exchange/USD/LTC/1?ref_id=654b33cfa4a0" target="_blank">Changelly</a></div>
</div>
';

  $export['footer_content'] = $fe_block_boxes;

  return $export;
}
