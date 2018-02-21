create procedure sp_v2_revert
as
BEGIN
alter table Rentals
drop constraint C
END
