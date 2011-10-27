<?php

/**
 * Field handler to present a transaction edit link.
 */
class ledger_handler_field_ledger_transaction_link_edit extends ledger_handler_field_ledger_transaction_link {
  function render($values) {
    
    // Ensure the user has access to edit this order.
    $transaction = ledger_transaction_new();
    $transaction->tid = $this->get_value($values, 'tid');

    if (!ledger_transaction_access('update', $transaction)) {
      return;
    }

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return l($text, 'admin/ledger/transactions/' . $transaction->tid . '/edit', array('query' => drupal_get_destination()));
  }
}
