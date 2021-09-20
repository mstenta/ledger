<?php

namespace Drupal\ledger_ledger\Form;

use Drupal\Core\Entity\ContentEntityForm;
use Drupal\Core\Form\FormStateInterface;

/**
 * Form controller for the ledger entity edit forms.
 */
class LedgerForm extends ContentEntityForm {

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
      $this->messenger()->addStatus($this->t('New ledger %label has been created.', $message_arguments));
      $this->logger('ledger_ledger')->notice('Created new ledger %label', $logger_arguments);
    }
    else {
      $this->messenger()->addStatus($this->t('The ledger %label has been updated.', $message_arguments));
      $this->logger('ledger_ledger')->notice('Updated new ledger %label.', $logger_arguments);
    }

    $form_state->setRedirect('entity.ledger.canonical', ['ledger' => $entity->id()]);
  }

}
