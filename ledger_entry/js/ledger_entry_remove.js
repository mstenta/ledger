/**
 * @file
 * Ledger entry field remove button javascript
 */

(function ($) {

  Drupal.behaviors.ledger_entry_remove = {
    attach: function (context, settings) {
      $('.ledger-entry-remove', context).click(function() {
        alert('not yet implemented');
      });
    }
  };

}(jQuery));