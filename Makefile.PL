#
# Makefile.PL - MakeMaker source for SecurID perl module
#
# $Id: Makefile.PL,v 1.3 2003/01/27 03:32:41 pliam Exp $
#

use ExtUtils::MakeMaker;

WriteMakefile(
	NAME => 'Crypt::securid',
	VERSION_FROM => 'SecurID.pm',
	'PREREQ_PM' => { 'Test::More' => 0.01 },
	OBJECT => 'sid.o securid.o securid_wrap.o'
);
