USE [lab1]
GO
/****** Object:  StoredProcedure [dbo].[sp_v4_upgrade]    Script Date: 11/14/2017 2:51:14 PM ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
ALTER procedure [dbo].[sp_v4_upgrade]
as
BEGIN
alter table Version4
add Foreign_Key int not null
END