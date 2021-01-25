Time Tokens
================

Time Tokens module provides tokens that lets you embed a date or time within formatted text so that it is displayed in the user's time zone. 

A typical usage would be to give the start time of an event in the body of a page that will be seen by people in multiple time zones.

Tokens are of the form

[time-tokens:datetime:_timestr_|_format_]

where

* _timestr_ is a string specifying the time in any format suitable for initializing a [DateTime object](https://www.php.net/manual/en/class.datetime).
  * To initialize from a Unix timestamp, prepend '@' to the timestamp, e.g., `@1611363600`.
  * To initialize from a time string, be sure to include the time zone explicitly, e.g., `2021-01-01 12:00 PST`; otherwise the user's local time zone is assumed (which would defeat the purpose of using this token).

* _format_ is a string giving the desired output formatting.
  * Formatting options are [documented in the PHP Manual](https://www.php.net/manual/en/datetime.format).

To initialize from a timestamp, you can convert a date to a timestamp using [EpochConverter](https://www.epochconverter.com).

Note that _timestr_ and _format_ are separated by a pipe (|), not a colon (:), because _timestr_ might contain a colon (typically separating hours and minutes).


Installation
------------

- Install this module using [the official Backdrop CMS instructions](https://backdropcms.org/guide/modules).

- Enable the "Replace tokens" filter for the text formats that you will be using these tokens in.

Documentation
-------------

Additional documentation is located in [the Wiki](https://github.com/backdrop-contrib/time-tokens/wiki/Documentation).

Issues
------

Bugs and feature requests should be reported in [the Issue Queue](https://github.com/backdrop-contrib/time_tokens/issues).

Current Maintainers
-------------------

- [Robert J. Lang](https://github.com/bugfolder).

Credits
-------

- Written for Backdrop CMS by [Robert J. Lang](https://github.com/bugfolder).

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.

