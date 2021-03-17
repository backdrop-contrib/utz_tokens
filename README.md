User Time Zone Tokens
================

This module provides tokens that lets you embed a date or time within formatted text so that it is displayed in the user's time zone.

Anonymous users will see it in the default time zone (typically the server time zone), but there is an option to detect their time zone as well (see below).

A typical usage would be to give the start time of an event in the body of a page that will be seen by people in multiple time zones.

Tokens are of the form

[utz-datetime:_datetime_|_format_]

where

* _datetime_ is a string specifying the time in any format suitable for initializing a [DateTime object](https://www.php.net/manual/en/class.datetime).
  * To initialize from a Unix timestamp, prepend '@' to the timestamp, e.g., `@1611363600`.
  * To initialize from a time string, be sure to include the time zone explicitly, e.g., `2021-01-01 12:00 PST`; otherwise the user's local time zone is assumed (which would defeat the purpose of using this token).

* _format_ is a string giving the desired output formatting, which can be either
  * The machine name of a Backdrop date/time format found at /admin/config/regional/date-time (e.g., `'short'`, `'medium'`, `'long'`), or
  * Any valid PHP formatting string. Formatting options are documented [in the PHP Manual](https://www.php.net/manual/en/datetime.format).

To initialize from a timestamp, you can convert a date to a timestamp using [EpochConverter](https://www.epochconverter.com).

Note that _datetime_ and _format_ are separated by a pipe (|), not a colon (:), because _datetime_ might contain a colon (typically separating hours and minutes).

You can use these tokens anywhere that tokens are accepted. To use the tokens in formatted text (the most common use case), install and enable the [Token Filter](https://backdropcms.org/project/token_filter) module.

There is an option to automatically detect the user's time zone (which is provided by their browser) and use that for anonymous or all users, which works even for cached pages. To use this capability you will need to install the [Luxon](https://github.com/bugfolder/luxon) module. With Luxon installed and enabled, on the configuration page for this module you will have the option to detect the user's time zone for anonymous or all users. This capability requires Javascript.

Installation
------------

Install this module using [the official Backdrop CMS instructions](https://backdropcms.org/guide/modules).

To use the tokens in formatted text, 

- Install and enable the [Token Filter](https://backdropcms.org/project/token_filter) module.
- Enable the "Replace tokens" filter for the text formats that you will be using these tokens in.

To automatically detect the time zone for anonymous or all users, 

- Install and enable the [Luxon](https://github.com/bugfolder/luxon) module.
- Go to /admin/config/regional/utz-tokens and check the desired option.

Documentation
-------------

Additional documentation is located in [the Wiki](https://github.com/backdrop-contrib/utz_tokens/wiki/Documentation).

Issues
------

Bugs and feature requests should be reported in [the Issue Queue](https://github.com/backdrop-contrib/utz_tokens/issues).

Similar Modules
---------------

User Time Zone Tokens handles time-zone-aware dates and times embedded within content as token text. If you're interested in applying time zone awareness to fields provided by the core Date module, have a look at the [Client Side Date Field Formatter](https://github.com/backdrop-contrib/cs_date_formatter) module.

Current Maintainers
-------------------

- [Robert J. Lang](https://github.com/bugfolder)

Credits
-------

- Written for Backdrop CMS by [Robert J. Lang](https://github.com/bugfolder).

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.

