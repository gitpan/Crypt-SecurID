# This file was automatically generated by SWIG
package Crypt::securid;
require Exporter;
require DynaLoader;
@ISA = qw(Exporter DynaLoader);

# version string
use vars qw($VERSION);
$VERSION = sprintf("%d.%02d", (q$Name: SecurID_Release_0_04 $ =~ /\d+/g));
# some minimal docs
=head1 NAME

Crypt::securid - this is a low-level module which you shouldn't use

=cut

package Crypt::securidc;
bootstrap Crypt::securid;
package Crypt::securid;
@EXPORT = qw( );

# ---------- BASE METHODS -------------

package Crypt::securid;

sub TIEHASH {
    my ($classname,$obj) = @_;
    return bless $obj, $classname;
}

sub CLEAR { }

sub FIRSTKEY { }

sub NEXTKEY { }

sub this {
    my $ptr = shift;
    return tied(%$ptr);
}


# ------- FUNCTION WRAPPERS --------

package Crypt::securid;


############# Class : Crypt::securid::SecurID ##############

package Crypt::securid::SecurID;
@ISA = qw( Crypt::securid );
%OWNER = ();
%ITERATORS = ();
sub new {
    my $pkg = shift;
    my @args = @_;
    my $self = Crypt::securidc::new_SecurID(@args);
    return undef if (!defined($self));
    $OWNER{$self} = 1;
    my %retval;
    tie %retval, "Crypt::securid::SecurID", $self;
    return bless \%retval, $pkg;
}

sub new_SecurIDbin () {
    my $pkg = shift;
    my @args = @_;
    my $self = Crypt::securidc::new_SecurIDbin(@args);
    return undef if (!defined($self));
    $OWNER{$self} = 1;
    my %retval;
    tie %retval, "Crypt::securid::SecurID", $self;
    return bless \%retval, $pkg;
}

sub new_SecurIDhex () {
    my $pkg = shift;
    my @args = @_;
    my $self = Crypt::securidc::new_SecurIDhex(@args);
    return undef if (!defined($self));
    $OWNER{$self} = 1;
    my %retval;
    tie %retval, "Crypt::securid::SecurID", $self;
    return bless \%retval, $pkg;
}

*setKey = *Crypt::securidc::SecurID_setKey;
*key = *Crypt::securidc::SecurID_key;
*drift = *Crypt::securidc::SecurID_drift;
*code = *Crypt::securidc::SecurID_code;
*codeNow = *Crypt::securidc::SecurID_codeNow;
*validate = *Crypt::securidc::SecurID_validate;
*importToken = *Crypt::securidc::SecurID_importToken;
*exportToken = *Crypt::securidc::SecurID_exportToken;
*error = *Crypt::securidc::SecurID_error;
sub DESTROY {
    return unless $_[0]->isa('HASH');
    my $self = tied(%{$_[0]});
    return unless defined $self;
    delete $ITERATORS{$self};
    if (exists $OWNER{$self}) {
        Crypt::securidc::delete_SecurID($self);
        delete $OWNER{$self};
    }
}

sub DISOWN {
    my $self = shift;
    my $ptr = tied(%$self);
    delete $OWNER{$ptr};
    };

sub ACQUIRE {
    my $self = shift;
    my $ptr = tied(%$self);
    $OWNER{$ptr} = 1;
    };


# ------- VARIABLE STUBS --------

package Crypt::securid;

1;
