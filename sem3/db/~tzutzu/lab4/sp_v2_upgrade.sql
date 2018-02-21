create procedure sp_v2_upgrade
as
BEGIN
alter table Rental
add constraint C
default 'hard' for difficulty
END
