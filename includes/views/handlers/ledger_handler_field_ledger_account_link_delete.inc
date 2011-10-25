<?php

/**
 * Field handler to present a link to delete an order.
 */
class ledger_handler_field_ledger_account_link_delete extends ledger_handler_field_ledger_account_link {
  function render($values) {
    
    // Ensure the user has access to edit this order.
    $account = ledger_account_new();
    $account->aid = $this->get_value($values, 'aid');

    if (!ledger_account_access('update', $account)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return l($text, 'ledger/accounts/' . $account->aid . '/delete', array('query' => drupal_get_destination()));
  }
}
