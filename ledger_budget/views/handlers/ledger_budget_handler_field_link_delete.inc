<?php

/**
 * @file
 * Field handler to present a link to delete a budget.
 */
class ledger_budget_handler_field_link_delete extends ledger_budget_handler_field_link {

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this budget.
    $budget = ledger_budget_new();
    $budget->bid = $this->get_value($values, 'bid');
    if (!ledger_budget_access('update', $budget)) {
      return;
    }

    // Load the link text, if it is defined in the options, otherwise just use "delete".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');

    // Return the text as a link to the budget delete page.
    return l($text, 'admin/ledger/budgets/' . $budget->bid . '/delete');
  }
}

