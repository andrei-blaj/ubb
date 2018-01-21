create procedure sp_v1_upgrade
as
BEGIN
alter table Positions
alter column Nume varchar(100)
END


