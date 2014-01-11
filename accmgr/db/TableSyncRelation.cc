#include "TableSyncRelation.hh"

string TableSyncRelation::insSQL="INSERT INTO TABLE_SYNC_RELATION(SOURCE_TABLE,SOURCE_COLUMN,DEST_TABLE,DEST_COLUMN,DATA_TYPE,DATA_VALUE,INDEX_FLAG,COMB_FLAG)VALUES (:SOURCE_TABLE,:SOURCE_COLUMN,:DEST_TABLE,:DEST_COLUMN,:DATA_TYPE,:DATA_VALUE,:INDEX_FLAG,:COMB_FLAG)";

void TableSyncRelation::insertData()
{
    setSQL(insSQL);
    executeUpdate();
}

void TableSyncRelation::prepareSQL()
{
    stmt->setString(1,table_sync_relation.m_source_table);
    stmt->setString(2,table_sync_relation.m_source_column);
    stmt->setString(3,table_sync_relation.m_dest_table);
    stmt->setString(4,table_sync_relation.m_dest_column);
    stmt->setString(5,table_sync_relation.m_data_type);
    stmt->setString(6,table_sync_relation.m_data_value);
    stmt->setString(7,table_sync_relation.m_index_flag);
    stmt->setString(8,table_sync_relation.m_comb_flag);
}

