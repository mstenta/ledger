<?php

/**
 * @file
 * Ledger Account UI theme functions.
 */

/**
 * Displays the list of available account types for account creation.
 */
function theme_ledger_account_add_list($variables) {
  $content = $variables['content'];

  if ($content) {
    $output = '<dl class="ledger-product-type-list">';
    foreach ($content as $item) {
      $output .= '<dt>' . l($item['title'], $item['href'], $item['localized_options']) . '</dt>';
      $output .= '<dd>' . filter_xss_admin($item['description']) . '</dd>';
    }
    $output .= '</dl>';
  }
  else {
    $output = '<p>' . t('You have not created any account types yet. Go to the <a href="@create-type">account type creation page</a> to add a new account type. Or, enable the Ledger Account Types module to automatically create the five standard types (Asset, Equity, Income, Expense, and Liability).', array('@create-type' => url('admin/config/ledger/account-types/add'))) . '</p>';
  }

  return $output;
}