create procedure sp_v5_revert
as
BEGIN
alter table Version4
drop constraint FK_Constraint
END