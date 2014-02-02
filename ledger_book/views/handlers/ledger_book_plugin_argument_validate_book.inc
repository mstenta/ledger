<?php

/**
 * @file
 * Contains the 'book' argument validator plugin.
 */

/**
 * Validate whether an argument is an acceptable book.
 */
class ledger_book_plugin_argument_validate_book extends views_plugin_argument_validate {
  function option_definition() {
    $options = parent::option_definition();
    $options['access'] = array('default' => FALSE, 'bool' => TRUE);
    $options['access_op'] = array('default' => 'view');
    $options['bid_type'] = array('default' => 'bid');

    return $options;
  }

  function options_form(&$form, &$form_state) {

    $form['access'] = array(
      '#type' => 'checkbox',
      '#title' => t('Validate user has access to the book'),
      '#default_value' => $this->options['access'],
    );
    $form['access_op'] = array(
      '#type' => 'radios',
      '#title' => t('Access operation to check'),
      '#options' => array('view' => t('View'), 'edit' => t('Edit')),
      '#default_value' => $this->options['access_op'],
      '#dependency' => array('edit-options-validate-options-book-access' => array(TRUE)),
    );

    $form['bid_type'] = array(
      '#type' => 'select',
      '#title' => t('Filter value format'),
      '#options' => array(
        'bid' => t('Book ID'),
        'bids' => t('Book IDs separated by , or +'),
      ),
      '#default_value' => $this->options['bid_type'],
    );
  }

  function validate_argument($argument) {

    switch ($this->options['bid_type']) {
      case 'bid':
        if (!is_numeric($argument)) {
          return FALSE;
        }
        $book = ledger_book_load($argument);
        if (!$book) {
          return FALSE;
        }

        if (!empty($this->options['access'])) {
          if (!ledger_book_access($this->options['access_op'], $book)) {
            return FALSE;
          }
        }

        // Save the title() handlers some work.
        $this->argument->validated_title = check_plain($book->name);

        // Valid!
        return TRUE;

      case 'bids':
        $bids = new stdClass();
        $bids->value = array($argument);
        $bids = views_break_phrase($argument, $bids);
        if ($bids->value == array(-1)) {
          return FALSE;
        }

        $test = drupal_map_assoc($bids->value);
        $titles = array();

        $result = db_query("SELECT * FROM {ledger_book} WHERE bid IN (:bids)", array(':bids' =>  $bids->value));
        foreach ($result as $book) {

          if (!empty($this->options['access'])) {
            if (!ledger_book_access($this->options['access_op'], $book)) {
              return FALSE;
            }
          }

          $titles[] = check_plain($book->name);
          unset($test[$book->bid]);
        }

        $this->argument->validated_title = implode($bids->operator == 'or' ? ' + ' : ', ', $titles);
        // If this is not empty, we did not find a bid.
        return empty($test);
    }
  }
}
