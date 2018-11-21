package examSampleWeb.converter;

import examSampleCore.model.BaseEntity;
import examSampleWeb.dto.BaseDto;

public interface Converter<Model extends BaseEntity<Long>, Dto extends BaseDto> {

    Model convertDtoToModel(Dto dto);

    Dto convertModelToDto(Model model);

}
