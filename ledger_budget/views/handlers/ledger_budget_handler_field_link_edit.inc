<?php

/**
 * @file
 * Field handler to present a budget edit link.
 */
class ledger_budget_handler_field_link_edit extends ledger_budget_handler_field_link {

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this budget.
    $budget = ledger_budget_new();
    $budget->bid = $this->get_value($values, 'bid');
    if (!ledger_budget_access('update', $budget)) {
      return;
    }

    // Load the link text, if it is defined in the options, otherwise just use "edit".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

    // Return the text as a link to the account edit page.
    return l($text, 'ledger/budget/' . $budget->bid . '/edit');
  }
}

