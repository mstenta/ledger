Ledger Import

Connects the Ledger module to the Feeds module to provide account and transaction import functionality.
Defines parser plugins for parsing various types of files.
Provides some default Feed importers for each parser that can be overridden by the user.

FeedsParsers:
  FeedsLedgerQIFParser - parses QIF files
  FeedsLedgerIIFParser - parses IIF files
  FeedsLedgerGnuCashParser - parses GnuCash XML files

FeedsProcessors:
  FeedsLedgerAccountProcessor - Creates Ledger Accounts from parsed content.
  FeedsLedgerTransactionProcessor - Creates Ledger Transactions from parsed content.

Menu items:
  /ledger/import
    Lists possible import methods
  /ledger/import/[qif/iif/gnucash]
    Feed importer for the particular file type