<?php

/**
 * @file
 * Contains ledger_account.page.inc.
 *
 * Page callback for Ledger Account entities.
 */

use Drupal\Core\Render\Element;
use Drupal\Core\Link;
use Drupal\Core\Url;

/**
 * Prepares variables for Ledger Account templates.
 *
 * Default template: ledger_account.html.twig.
 *
 * @param array $variables
 *   An associative array containing:
 *   - elements: An associative array containing the user information and any
 *   - attributes: HTML attributes for the containing element.
 */
function template_preprocess_ledger_account(array &$variables) {
  // Fetch LedgerAccount Entity Object.
  $ledger_account = $variables['elements']['#ledger_account'];

  // Helpful $content variable for templates.
  foreach (Element::children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }
}

/**
* Prepares variables for a custom entity type creation list templates.
*
* Default template: ledger_account-content-add-list.html.twig.
*
* @param array $variables
*   An associative array containing:
*   - content: An array of ledger_account-types.
*
* @see block_content_add_page()
*/
function template_preprocess_ledger_account_content_add_list(&$variables) {
  $variables['types'] = array();
  $query = \Drupal::request()->query->all();
  foreach ($variables['content'] as $type) {
    $variables['types'][$type->id()] = array(
      'link' => Link::fromTextAndUrl($type->label(), new Url('entity.ledger_account.add_form', array(
        'ledger_account_type' => $type->id()
      ), array('query' => $query))),
      'description' => array(
      '#markup' => $type->label(),
      ),
      'title' => $type->label(),
      'localized_options' => array(
      'query' => $query,
      ),
    );
  }
}
