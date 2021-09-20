<?php

namespace Drupal\ledger_account\Form;

use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Form\FormStateInterface;

/**
 * Form controller for the account entity edit forms.
 */
class LedgerAccountForm extends ContentEntityForm {

  /**
   * {@inheritdoc}
   */
  public function save(array $form, FormStateInterface $form_state) {

    $entity = $this->getEntity();
    $result = $entity->save();
    $link = $entity->toLink($this->t('View'))->toRenderable();

    $message_arguments = ['%label' => $this->entity->label()];
    $logger_arguments = $message_arguments + ['link' => render($link)];

    if ($result == SAVED_NEW) {
      $this->messenger()->addStatus($this->t('New account %label has been created.', $message_arguments));
      $this->logger('ledger_account')->notice('Created new account %label', $logger_arguments);
    }
    else {
      $this->messenger()->addStatus($this->t('The account %label has been updated.', $message_arguments));
      $this->logger('ledger_account')->notice('Updated new account %label.', $logger_arguments);
    }

    $form_state->setRedirect('entity.ledger_account.canonical', ['ledger_account' => $entity->id()]);
  }

}
